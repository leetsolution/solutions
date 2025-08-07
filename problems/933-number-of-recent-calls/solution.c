#include <stdlib.h>

typedef struct {
    int *requests;
    int size;
    int capacity;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->requests = (int*)malloc(sizeof(int) * 10000);
    obj->size = 0;
    obj->capacity = 10000;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->requests[obj->size++] = t;
    int lowerBound = t - 3000;
    int count = 0;
    int left = 0;
    int right = obj->size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (obj->requests[mid] >= lowerBound) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return obj->size - left;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->requests);
    free(obj);
}