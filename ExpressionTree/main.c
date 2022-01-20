#include <stdio.h>
#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*";
	BTreeNode* ExpTree = MakeExpTree(exp);

	printf("전위 표기법의 수식: ");
	ShowPrefixTypeExp(ExpTree);
	printf("\n");

	printf("중위 표기법의 수식: ");
	ShowInfixTypeExp(ExpTree);
	printf("\n");

	printf("후위 표기법의 수식: ");
	ShowPostfixTypeExp(ExpTree);
	printf("\n");

	printf("연산 결과 : %d \n", EvaluateExpTree(ExpTree));

	return 0;
}