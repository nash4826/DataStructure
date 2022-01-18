#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
	plist->cur = -1;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data) {
	if (plist->numOfData >= ARRAY_LEN)
	{
		puts("memory over\n");
		return;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData == 0)
		return FALSE;
	(plist->cur) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur >= (plist->numOfData) - 1)
		return FALSE;
	(plist->cur)++;
	*pdata = plist->arr[plist->cur];
	return TRUE;
}

LData LRemove(List* plist) {
	int rpos = plist->cur;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->cur)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}
