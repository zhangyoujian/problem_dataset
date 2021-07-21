#include <stdio.h>
#include <stdlib.h>

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PriorityQueue {
    int front;
    int count;
    int *buffer;
} PriorityQueue;

PriorityQueue *PriQueueCreate(int size);

void PriQueueDestroy(PriorityQueue *queue);

int PriQueueSize(PriorityQueue *queue);

int PriQueueGetFront(PriorityQueue *queue);

void PriQueuePush(PriorityQueue *queue, int data);

#ifdef _cplusplus
}
#endif

#endif



