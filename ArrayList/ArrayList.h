#pragma once
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define ARRAY_LEN	100
#define TRUE	1
#define FALSE	0
typedef int LData;

typedef struct _arraylist {
	int arr[ARRAY_LEN];
	int cur;
	int numOfData;
}List;

void ListInit(List* plist);

void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);

int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);

int LCount(List* plist);
#endif // !__ARRAY_LIST_H__
