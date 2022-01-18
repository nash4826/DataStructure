#include <stdio.h>

int LSearch(int arr[], int len, int target) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == target)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 3,5,2,4,9 };
	printf("target : %d -> index : %d\n", 4,LSearch(arr, sizeof(arr) / sizeof(int), 4));
	return 0;
}