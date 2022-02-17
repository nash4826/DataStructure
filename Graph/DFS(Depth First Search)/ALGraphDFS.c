#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

//정렬
int WhoIsPrecede(int data1, int data2);

//그래프 초기화
void GraphInit(ALGraph* pg, int nv)
{
	//정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = malloc(sizeof(List) * nv); 
		
	pg->numV = nv; //정점의 수
	pg->numE = 0; //간선의 수(초기값 0)

	//정점의 수를 길이로 하여 배열을 할당과 0으로 초기화(일종의 방문 정보(기록))
	pg->visitInfo = malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	

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

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
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

//정점의 방문 진행
int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) //visitV에 처음 방문일 때 'True'인 if문
	{
		pg->visitInfo[visitV] = 1; // visitV에 방문한 것으로 기록
		printf("%c ", visitV + 65); //방문한 정점의 이름을 출력
		return TRUE; //방문성공
	}
	return FALSE; // 방문 실패
}
//정점의 정보 출력 : Depth First Search 기반
void DFShowGraphVertex(ALGraph* pg, int startV)
{
	/*
		Stack을 이용하여 경로 정보를 추적한다.(하나하나 경로정보를 쌓는다)
		Depth의 의미에 맞게 하나하나 깊이 추적하다가 종점에 다다르면
		Stack의 pop기능으로 다시 우회한다.
		2개 이상으로 분기되어 있는 정점 중에 방문하지 않은 정점이 있다면 그곳을 추적한다.
		그리고 모든 경로를 다 방문하면 Stack에 쌓여있는 정점을 중심으로
		pop하여 처음 시작 정점(startV)으로 되돌아간다.
		
		P.S
		Stack의 pop으로 다시 우회한다는 점은 재귀구조와 흡사하다.
		알고리즘 책을 확인한 결과,
		'DFS는 스택과 재귀로 구현한다'는 사실을 알게 되었다.
		BFS는 Queue(큐)를 이용하며, 재귀로는 구현할 수 없다.
	*/
	Stack stack; //경로 정보의 추적 목적으로 Stack을 쓴다.
	int visitV = startV;
	int nextV;

	StackInit(&stack); //stack 초기화
	VisitVertex(pg, visitV); //시작 정점(startV)방문
	SPush(&stack, visitV); //시작 정점의 정보를 스택으로!

	//visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 While문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		//visitV에 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) // 방문에 성공했다면
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else //방문에 성공하지 못했다면, 연결된 다른 정점들을 찾는다.
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) //추가로 방문한 정점이 없었다면
		{
			//Stack이 비면 탐색의 시작점으로 되돌아 온 것임!!

			if (SIsEmpty(&stack) == TRUE) //시작점으로 되돌아왔음!
				break;
			else
				visitV = SPop(&stack); // 시작점으로 되돌아간다.
		}
	}

	//이후의 탐색을 위해서 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}