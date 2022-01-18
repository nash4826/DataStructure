#pragma once
#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _list {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}List;

void ListInit(List* plist);

void LInsert(List* plist, LData data);
void LInsertFront(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);

int LCount(List* plist);
#endif // !__C_LINKED_LIST_H__
