#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int NextPos(int pos) // the important algorithm of circle Queue 
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	if (NextPos(pq->rear) == pq->front)
	{
		printf("Queue Memory Full\n");
		exit(-1);
	}
	pq->rear = NextPos(pq->rear);
	pq->queArr[pq->rear] = data;

}

Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Empty\n");
		exit(-1);
	}
	pq->front = NextPos(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Empty\n");
		exit(-1);
	}
	return pq->queArr[NextPos(pq->front)];
}
