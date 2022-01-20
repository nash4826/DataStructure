#pragma once
#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

/*
���� ǥ����� ������ ���� ǥ������� ��ȯ ��, ���� Ʈ���� ��ȯ
���� ǥ��� -> ���� ǥ��� -> ���� Ʈ��
Stack �ʿ�.
*/

#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode* bt);


//���� Ʈ���� ���� �Լ�.
void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);

#endif // !__EXPRESSION_TREE_H__
