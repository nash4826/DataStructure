#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "BinaryTree.h"
#include "ListBaseStack.h"

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* node;

	int expLen = strlen(exp);
	int i;

	StackInIt(&stack);

	for (i = 0; i < expLen; i++)
	{
		node = MakeBTreeNode();

		if (isdigit(exp[i]))
		{
			SetData(node, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(node, SPop(&stack));
			MakeLeftSubTree(node, SPop(&stack));
			SetData(node, exp[i]);
		}

		SPush(&stack, node);
	}

	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}


//수식 트리의 검증 함수.

void ShowData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d", data);
	else
		printf("%c", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowData);
}
void ShowInfixTypeExp(BTreeNode* bt) // 중위표기법 수식(괄호 추가)
{
	if (bt == NULL)
		return;

	if(bt->left != NULL || bt->right != NULL)
		printf("(");

	ShowInfixTypeExp(bt->left);
	ShowData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(")");

}
void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowData);
}