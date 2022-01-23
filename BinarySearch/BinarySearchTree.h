#pragma once
#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree(Serach).h"

typedef BTData BSTData;

//���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot);

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst);

//�̽� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data);

//���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

//Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּҰ� ��ȯ(�޸� ����X => �޸� ��ü å���� �Լ��� ���� �ʴ´�)
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

//���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�(������ȸ �������)
void BSTShowAll(BTreeNode* bst);


#endif