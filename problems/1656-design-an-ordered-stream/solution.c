#include <stdlib.h>
#include <string.h>

typedef struct {
    char** stream;
    int ptr;
    int size;
} OrderedStream;


OrderedStream* orderedStreamCreate(int n) {
    OrderedStream* obj = (OrderedStream*)malloc(sizeof(OrderedStream));
    obj->stream = (char**)malloc(sizeof(char*) * (n + 1));
    obj->ptr = 1;
    obj->size = n;
    for (int i = 0; i <= n; i++) {
        obj->stream[i] = NULL;
    }
    return obj;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int* retSize) {
    obj->stream[idKey] = (char*)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(obj->stream[idKey], value);

    char** result = (char**)malloc(sizeof(char*) * (obj->size + 1));
    *retSize = 0;

    while (obj->ptr <= obj->size && obj->stream[obj->ptr] != NULL) {
        result[*retSize] = obj->stream[obj->ptr];
        (*retSize)++;
        obj->ptr++;
    }

    if (*retSize > 0) {
        result = (char**)realloc(result, sizeof(char*) * (*retSize));
        return result;
    } else {
        free(result);
        return (char**)malloc(0);
    }
}

void orderedStreamFree(OrderedStream* obj) {
    for (int i = 1; i <= obj->size; i++) {
        if (obj->stream[i] != NULL) {
            free(obj->stream[i]);
        }
    }
    free(obj->stream);
    free(obj);
}