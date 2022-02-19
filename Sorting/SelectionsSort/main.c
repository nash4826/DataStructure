#include <stdio.h>

/*
	*Selection Sort*
	
	* Time Complexity : O(n^2)
	
*/
void selection_sort(int* arr, int size)
{
	int maxIndex;
	int temp;

	for (int i = 0; i < size - 1; i++)
	{
		maxIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[maxIndex])
				maxIndex = j;
		}
		temp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
}

int main()
{
	int arr[10] = { 7,2,6,1,5,3,10,4,9,8 };
	
	selection_sort(arr, sizeof(arr) / sizeof(int));
	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}