#pragma once
#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"
#include "DLinkedList.h"

#define MAX_TBL	100

typedef int HashFunc(Key k);

typedef struct _table {
	List tbl[MAX_TBL];
	HashFunc* hf;
}Table;

//���̺� �ʱ�ȭ
void TBLInit(Table* pt, HashFunc* f);

//���̺� Ű�� ���� ����
void TBLInsert(Table* pt, Key k, Value v);

//key�� �ٰŷ� ���̺��� ������ ����
Value TBLDelete(Table* pt, Key k);

//key�� �ٰŷ� ���̺��� ������ Ž��
Value TBLSearch(Table* pt, Key k);


#endif // 
