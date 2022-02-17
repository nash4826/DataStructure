/*
		**DFS**
		
		Stack�� �̿��Ͽ� ��� ������ �����Ѵ�.(�ϳ��ϳ� �������(����)�� �״´�)
		
		Depth�� �ǹ̿� �°� �ϳ��ϳ� ���� �����ϴٰ� ������ �ٴٸ���
		Stack�� pop������� �ٽ� ��ȸ�Ѵ�.
		2�� �̻����� �б�Ǿ� �ִ� ���� �߿� �湮���� ���� ������ �ִٸ� �װ��� �����Ѵ�.
		�׸��� ��� ��θ� �� �湮�ϸ� Stack�� �׿��ִ� ������ �߽�����
		pop�Ͽ� ó�� ���� ����(startV)���� �ǵ��ư���.

		Array�� �湮��������� �����ϸ� ����.
		���� ���, A~G���� ������ 7���� ������ ���� �׷������� DFS�� ���ٸ�
		�� ������ '�湮�ߴ�'�� ����� ����� ������ Array�� �Ѵ�.

		P.S
		Stack�� pop���� �ٽ� ��ȸ�Ѵٴ� ���� ��ͱ����� ����ϴ�.
		�˰��� å�� Ȯ���� ���,
		'DFS�� ���ð� ��ͷ� �����Ѵ�'�� ����� �˰� �Ǿ���.
		BFS�� Queue(ť)�� �̿��ϸ�, ��ͷδ� ������ �� ����.
	*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ALGraphDFS.h"
int main()
{
	ALGraph graph; //�׷��� ����
	GraphInit(&graph,7); //�׷��� �ʱ�ȭ

	AddEdge(&graph, A, B); //���� A�� B�� ����
	AddEdge(&graph, A, D); //���� A�� D�� ����
	AddEdge(&graph, B, C); //���� B�� C�� ����
	AddEdge(&graph, D, C); //���� D�� C�� ����
	AddEdge(&graph, D, E); //���� D�� E�� ����
	AddEdge(&graph, E, F); //���� E�� F�� ����
	AddEdge(&graph, E, G); //���� E�� G�� ����
	
	ShowGraphEdgeInfo(&graph); //�׷����� ���� ���� ���
	
	printf("===============================\n");

	printf("DFS ���� ���� : A\n");
	DFShowGraphVertex(&graph, A);
	printf("\n");
	
	printf("DFS ���� ���� : C\n");
	DFShowGraphVertex(&graph, C);
	printf("\n");

	printf("DFS ���� ���� : E\n");
	DFShowGraphVertex(&graph, E);
	printf("\n");

	printf("DFS ���� ���� : G\n");
	DFShowGraphVertex(&graph, G);
	printf("\n");

	
	GraphDestroy(&graph); //�׷��� ���ҽ� ����(�޸� ����)

	return 0;
}