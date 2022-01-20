#pragma once
#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

/*
중위 표기법의 수식을 후위 표기법으로 변환 후, 수식 트리로 전환
중위 표기법 -> 후위 표기법 -> 수식 트리
Stack 필요.
*/

#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode* bt);


//수식 트리의 검증 함수.
void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);

#endif // !__EXPRESSION_TREE_H__
