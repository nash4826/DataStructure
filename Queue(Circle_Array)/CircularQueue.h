#pragma once
#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE	1
#define FALSE	0

#define QUE_LEN	100

typedef int Data;

typedef struct _queue {
	int front;
	int rear;
	Data queArr[QUE_LEN];
}Queue;

void QueueInit(Queue* pq);

int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);

Data Dequeue(Queue* pq);

Data QPeek(Queue* pq);

#endif // !__CIRCULAR_QUEUE_H__
