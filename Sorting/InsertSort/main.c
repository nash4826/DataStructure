#include <stdio.h>

/*
	*Insert Sort*
	
	* Time Complexity : O(n^2)
	
*/
void InsertSort(int* arr, int size)
{
	int i, j;
	int insData;
	for (i = 1; i < size; i++)
	{
		insData = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
	
}

int main()
{
	int arr[10] = { 7,2,6,1,5,3,10,4,9,8 };
	
	InsertSort(arr, sizeof(arr) / sizeof(int));
	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}