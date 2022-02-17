#pragma once

//������ �׷���
#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#include "DLinkedList.h" //���Ḯ��Ʈ ���
enum {
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J
};

typedef struct _ual
{
	int numV;	//������ ��
	int numE;	//������ ��
	List* adjList; //������ ����
}ALGraph;

//�׷��� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

#endif