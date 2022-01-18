#include <stdio.h>
#include "DLinkedList.h"

int sortfunction(LData d1, LData d2) {
	if (d1 > d2)
		return 1;
	else
		return 0;
}

int main()
{
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list, sortfunction);

	LInsert(&list, 11);
	LInsert(&list, 33);
	LInsert(&list, 22);
	LInsert(&list, 55);
	LInsert(&list, 44);

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n====================\n");
	if (LFirst(&list, &data))
	{
		if (data == 44)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data == 44)
				LRemove(&list);

		}
	}
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	return 0;
}