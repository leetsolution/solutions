typedef struct {
    int *keys;
    int size;
    int capacity;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    obj->size = 0;
    obj->capacity = 1000; 
    obj->keys = (int*)calloc(obj->capacity, sizeof(int));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (myHashSetContains(obj, key)) return;
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->keys = (int*)realloc(obj->keys, obj->capacity * sizeof(int));
    }
    obj->keys[obj->size++] = key;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int i;
    for (i = 0; i < obj->size; i++) {
        if (obj->keys[i] == key) {
            obj->keys[i] = obj->keys[--obj->size];
            break;
        }
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int i;
    for (i = 0; i < obj->size; i++) {
        if (obj->keys[i] == key) {
            return true;
        }
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->keys);
    free(obj);
}