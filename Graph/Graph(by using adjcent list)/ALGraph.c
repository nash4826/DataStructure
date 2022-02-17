#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

//정렬
int WhoIsPrecede(int data1, int data2);

//그래프 초기화
void GraphInit(ALGraph* pg, int nv)
{
	//정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = malloc(sizeof(List) * nv); 
		
	pg->numV = nv; //정점의 수
	pg->numE = 0; //간선의 수(초기값 0)

	//정점의 수만큼 생성된 리스트들을 초기화한다.
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); //리스트의 정렬기준을 설정(알파벳 순으로)
	}
}

//그래프의 리소스 해제
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
}

//간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;
	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);//i+65 는 아스키코드표 참고
		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);
			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}