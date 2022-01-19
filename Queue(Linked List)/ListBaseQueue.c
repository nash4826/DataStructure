#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	/* before refactoring 
	if (pq->front == NULL)
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	*/

	// After refactoring
	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}

}

Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Empty\n");
		exit(-1);
	}

	Node* rpos = pq->front;
	Data rdata = rpos->data;
	
	pq->front = pq->front->next;
	free(rpos);
	return rdata;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Empty\n");
		exit(-1);
	}
	return pq->front->data;

}