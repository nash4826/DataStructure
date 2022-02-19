/*
	**Merge Sort**
	
	* Time Complexity : O(n log n)

	���� ���Ŀ��� �ӽ� �޸𸮰� �ʿ��ϴٴ� ������ �ִ�.
	������ ������ ����� �迭�� �ƴ� ���� ����Ʈ�� ��� ������ ���� �ʱ� ������
	���� ����Ʈ�� ��쿡�� ���� ���Ŀ��� �� ���� ������ ����� �� �ִ�.
	
	�Ʒ� ���� ���Ŀ��� ������ ����� �迭�̴�.
*/
#include <stdio.h>
#include <stdlib.h>

//�ΰ��� �迭�� �����ϴ� �Լ�
void MergeTwoArea(int* arr, int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	int* sortArr = malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (int i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int* arr, int left, int right)
{
	int mid;
	
	if (left < right)
	{
		//�߰����� ���
		mid = (left + right) / 2;

		//�ѷ� ������ ���� ����
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		//���ĵ� �� �迭�� ����
		MergeTwoArea(arr, left, mid, right);
	}
}

int main()
{
	int arr[10] = { 7,2,6,1,5,3,10,4,9,8 };
	
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}