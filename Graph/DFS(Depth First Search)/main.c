/*
		**DFS**
		
		Stack을 이용하여 경로 정보를 추적한다.(하나하나 경로정보(정점)를 쌓는다)
		
		Depth의 의미에 맞게 하나하나 깊이 추적하다가 종점에 다다르면
		Stack의 pop기능으로 다시 우회한다.
		2개 이상으로 분기되어 있는 정점 중에 방문하지 않은 정점이 있다면 그곳을 추적한다.
		그리고 모든 경로를 다 방문하면 Stack에 쌓여있는 정점을 중심으로
		pop하여 처음 시작 정점(startV)으로 되돌아간다.

		Array는 방문기록장으로 생각하면 쉽다.
		예를 들어, A~G으로 구성된 7개의 정점을 가진 그래프에서 DFS을 쓴다면
		각 정점을 '방문했다'는 기록을 남기는 역할을 Array가 한다.

		P.S
		Stack의 pop으로 다시 우회한다는 점은 재귀구조와 흡사하다.
		알고리즘 책을 확인한 결과,
		'DFS는 스택과 재귀로 구현한다'는 사실을 알게 되었다.
		BFS는 Queue(큐)를 이용하며, 재귀로는 구현할 수 없다.
	*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ALGraphDFS.h"
int main()
{
	ALGraph graph; //그래프 생성
	GraphInit(&graph,7); //그래프 초기화

	AddEdge(&graph, A, B); //정점 A와 B를 연결
	AddEdge(&graph, A, D); //정점 A와 D를 연결
	AddEdge(&graph, B, C); //정점 B와 C를 연결
	AddEdge(&graph, D, C); //정점 D와 C를 연결
	AddEdge(&graph, D, E); //정점 D와 E를 연결
	AddEdge(&graph, E, F); //정점 E와 F를 연결
	AddEdge(&graph, E, G); //정점 E와 G를 연결
	
	ShowGraphEdgeInfo(&graph); //그래프의 간선 정보 출력
	
	printf("===============================\n");

	printf("DFS 시작 정점 : A\n");
	DFShowGraphVertex(&graph, A);
	printf("\n");
	
	printf("DFS 시작 정점 : C\n");
	DFShowGraphVertex(&graph, C);
	printf("\n");

	printf("DFS 시작 정점 : E\n");
	DFShowGraphVertex(&graph, E);
	printf("\n");

	printf("DFS 시작 정점 : G\n");
	DFShowGraphVertex(&graph, G);
	printf("\n");

	
	GraphDestroy(&graph); //그래프 리소스 해제(메모리 해제)

	return 0;
}