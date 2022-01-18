#include <stdio.h>
#include "CLinkedList.h"

int main()
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		for (int i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}

}