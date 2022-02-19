/*
	**Heap Sort**
	
	* Time Complexity : O(n log n)

*/
#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2 - n1; //�������� ����
	//return n1 - n2; //�������� ����
}

void HeapSort(int* arr, int size, PriorityComp pc)
{
	Heap heap;
	HeapInit(&heap, pc);

	//���Ĵ���� arr�� ������ Heap�� �����Ѵ�.
	for (int i = 0; i < size; i++)
		HInsert(&heap, arr[i]);

	//������� �ϳ��� ������ ���� �ϼ�!
	for (int i = 0; i < size; i++)
		arr[i] = HDelete(&heap);

}

int main()
{
	int arr[10] = { 7,2,6,1,5,3,10,4,9,8 };
	
	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}