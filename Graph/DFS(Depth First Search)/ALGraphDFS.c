#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

//����
int WhoIsPrecede(int data1, int data2);

//�׷��� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv)
{
	//������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = malloc(sizeof(List) * nv); 
		
	pg->numV = nv; //������ ��
	pg->numE = 0; //������ ��(�ʱⰪ 0)

	//������ ���� ���̷� �Ͽ� �迭�� �Ҵ�� 0���� �ʱ�ȭ(������ �湮 ����(���))
	pg->visitInfo = malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	

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

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
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

//������ �湮 ����
int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) //visitV�� ó�� �湮�� �� 'True'�� if��
	{
		pg->visitInfo[visitV] = 1; // visitV�� �湮�� ������ ���
		printf("%c ", visitV + 65); //�湮�� ������ �̸��� ���
		return TRUE; //�湮����
	}
	return FALSE; // �湮 ����
}
//������ ���� ��� : Depth First Search ���
void DFShowGraphVertex(ALGraph* pg, int startV)
{
	/*
		Stack�� �̿��Ͽ� ��� ������ �����Ѵ�.(�ϳ��ϳ� ��������� �״´�)
		Depth�� �ǹ̿� �°� �ϳ��ϳ� ���� �����ϴٰ� ������ �ٴٸ���
		Stack�� pop������� �ٽ� ��ȸ�Ѵ�.
		2�� �̻����� �б�Ǿ� �ִ� ���� �߿� �湮���� ���� ������ �ִٸ� �װ��� �����Ѵ�.
		�׸��� ��� ��θ� �� �湮�ϸ� Stack�� �׿��ִ� ������ �߽�����
		pop�Ͽ� ó�� ���� ����(startV)���� �ǵ��ư���.
		
		P.S
		Stack�� pop���� �ٽ� ��ȸ�Ѵٴ� ���� ��ͱ����� ����ϴ�.
		�˰��� å�� Ȯ���� ���,
		'DFS�� ���ð� ��ͷ� �����Ѵ�'�� ����� �˰� �Ǿ���.
		BFS�� Queue(ť)�� �̿��ϸ�, ��ͷδ� ������ �� ����.
	*/
	Stack stack; //��� ������ ���� �������� Stack�� ����.
	int visitV = startV;
	int nextV;

	StackInit(&stack); //stack �ʱ�ȭ
	VisitVertex(pg, visitV); //���� ����(startV)�湮
	SPush(&stack, visitV); //���� ������ ������ ��������!

	//visitV�� ��� ������ ����� ������ �湮�� �õ��ϴ� While��
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		//visitV�� ����� ������ ������ nextV�� ��� ���¿��� ���ϸ� ����
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) // �湮�� �����ߴٸ�
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else //�湮�� �������� ���ߴٸ�, ����� �ٸ� �������� ã�´�.
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

		if (visitFlag == FALSE) //�߰��� �湮�� ������ �����ٸ�
		{
			//Stack�� ��� Ž���� ���������� �ǵ��� �� ����!!

			if (SIsEmpty(&stack) == TRUE) //���������� �ǵ��ƿ���!
				break;
			else
				visitV = SPop(&stack); // ���������� �ǵ��ư���.
		}
	}

	//������ Ž���� ���ؼ� Ž�� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}