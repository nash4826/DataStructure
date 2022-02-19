#include <stdio.h>

/*
	*bubble Sort*
	
	* Time Complexity : O(n^2)
	
*/

void bubble_sort(int* arr, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	int arr[10] = { 7,2,6,1,5,3,10,4,9,8 };
	bubble_sort(arr, sizeof(arr) / sizeof(int));
	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}