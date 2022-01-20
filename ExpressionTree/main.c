#include <stdio.h>
#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*";
	BTreeNode* ExpTree = MakeExpTree(exp);

	printf("���� ǥ����� ����: ");
	ShowPrefixTypeExp(ExpTree);
	printf("\n");

	printf("���� ǥ����� ����: ");
	ShowInfixTypeExp(ExpTree);
	printf("\n");

	printf("���� ǥ����� ����: ");
	ShowPostfixTypeExp(ExpTree);
	printf("\n");

	printf("���� ��� : %d \n", EvaluateExpTree(ExpTree));

	return 0;
}