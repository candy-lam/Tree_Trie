#ifndef QUEUE_H
#define QUEUE_H
#include "Tree.h"

typedef struct queueCDT *queueADT;
typedef struct customer *customerT;
typedef TreeADT queueElementT;

queueADT EmptyQueue(void);
void Enqueue(queueADT queue, queueElementT element);
queueElementT Dequeue(queueADT queue);
int QueueLength(queueADT queue);
int QueueIsEmpty(queueADT queue);


#endif
