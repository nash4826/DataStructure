/*
	**Merge Sort**
	
	* Time Complexity : O(n log n)

	병합 정렬에는 임시 메모리가 필요하다는 단점이 있다.
	하지만 정렬의 대상이 배열이 아닌 연결 리스트일 경우 단점이 되지 않기 때문에
	연결 리스트의 경우에는 병합 정렬에서 더 좋은 성능을 기대할 수 있다.
	
	아래 병합 정렬에서 정렬의 대상은 배열이다.
*/
#include <stdio.h>
#include <stdlib.h>

//두개의 배열을 병합하는 함수
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
		//중간지점 계산
		mid = (left + right) / 2;

		//둘로 나눠서 각각 정렬
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		//정렬된 두 배열을 병합
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