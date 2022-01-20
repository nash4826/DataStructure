#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1; // 아스키코드값 기준으로 우선순위
}
int main()
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	PEnqueue(&pq, 'D');
	PEnqueue(&pq, 'E');

	while (!PQIsEmpty(&pq))
		printf("%c ", PDequeue(&pq));

	return 0;
}