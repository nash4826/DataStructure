#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int num, char from, char by, char to) {
	if (num == 1)
		printf("���� 1�� %c���� %c�� �̵�\n", from, to);
	else {
		hanoi(num - 1,from, to, by);
		printf("���� %d�� %c���� %c�� �̵�\n", num,from, to);
		hanoi(num - 1, by, from, to);
	}
}
int main()
{
	hanoi(3, 'a', 'b', 'c');
	return 0;
}
	