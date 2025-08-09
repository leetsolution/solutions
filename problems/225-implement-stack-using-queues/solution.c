#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *queue;
    int head;
    int tail;
    int size;
    int capacity;
} Queue;

typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;


Queue* queueCreate(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->queue = (int*)malloc(sizeof(int) * capacity);
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

bool queueIsEmpty(Queue* queue) {
    return queue->size == 0;
}

void queuePush(Queue* queue, int x) {
    if (queue->size == queue->capacity) return;
    queue->queue[queue->tail++] = x;
    queue->size++;
    queue->tail %= queue->capacity;
}

int queuePop(Queue* queue) {
    if (queueIsEmpty(queue)) return -1; 
    int val = queue->queue[queue->head++];
    queue->size--;
    queue->head %= queue->capacity;
    return val;
}

int queueFront(Queue* queue) {
    if (queueIsEmpty(queue)) return -1;
    return queue->queue[queue->head];
}


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q1 = queueCreate(100);
    obj->q2 = queueCreate(100);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    queuePush(obj->q1, x);
}

int myStackPop(MyStack* obj) {
    if (queueIsEmpty(obj->q1)) return -1;
    while (obj->q1->size > 1) {
        queuePush(obj->q2, queuePop(obj->q1));
    }
    int top = queuePop(obj->q1);
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return top;
}

int myStackTop(MyStack* obj) {
    if (queueIsEmpty(obj->q1)) return -1;
    while (obj->q1->size > 1) {
        queuePush(obj->q2, queuePop(obj->q1));
    }
    int top = queueFront(obj->q1);
    queuePush(obj->q2, queuePop(obj->q1));
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return top;
}

bool myStackEmpty(MyStack* obj) {
    return queueIsEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1->queue);
    free(obj->q1);
    free(obj->q2->queue);
    free(obj->q2);
    free(obj);
}