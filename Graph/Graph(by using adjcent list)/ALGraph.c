#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

//����
int WhoIsPrecede(int data1, int data2);

//�׷��� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv)
{
	//������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = malloc(sizeof(List) * nv); 
		
	pg->numV = nv; //������ ��
	pg->numE = 0; //������ ��(�ʱⰪ 0)

	//������ ����ŭ ������ ����Ʈ���� �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); //����Ʈ�� ���ı����� ����(���ĺ� ������)
	}
}

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
}

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;
	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);//i+65 �� �ƽ�Ű�ڵ�ǥ ����
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