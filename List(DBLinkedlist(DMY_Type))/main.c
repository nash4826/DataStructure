#include <stdio.h>
#include "DBDLinkedList.h"

int main()
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	return 0;
}