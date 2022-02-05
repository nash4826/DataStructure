#include <stdio.h>
#include "BinaryTree3.h"

//LLȸ��
BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// cNode�� ������ ���� Ʈ��(������)�� pNode�� ���� ���� Ʈ���� ��ü
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode)); 
	ChangeRightSubTree(cNode, pNode); //LL ȸ��

	return cNode; // ���뷱�� ���� cNode�� pNode�� �Ǿ��� ������ cNode �ּҰ� ��ȯ
}

//RRȸ��
BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

//RL ȸ��
BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode)); //�κ��� LLȸ��
	return RotateRR(pNode); //RRȸ��
}

//LR ȸ��
BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

//Ʈ���� ���̸� ����Ͽ� ��ȯ

int GetHeight(BTreeNode* bst)
{
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	//���� ���� Ʈ�� ���� ���
	leftH = GetHeight(GetLeftSubTree(bst));
	//������ ���� Ʈ�� ���� ���
	rightH = GetHeight(GetRightSubTree(bst));

	//ū ���� ���̸� ��ȯ
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}


// �� ���� Ʈ���� ������ ���� ��ȯ(���� �μ� �Լ�)
int GetHeightDiff(BTreeNode* bst)
{
/*
	���� �μ� = ���� ���� Ʈ���� ���� - ������ ���� Ʈ���� ����
	AVL Ʈ���� ���� �μ��� ���밪�� 2 �̻��� ��� ���뷱�̿� ����.
*/
	int lsh; //left sub tree height
	int rsh; //right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
	
}

//���뷱��
BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if (hDiff > 1) //���� ���� Ʈ�� �������� ���̰� 2 �̻��� ���
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	if (hDiff < -1) // ������ ���� Ʈ�� �������� ���̰� 2 �̻��� ���
	{
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;
}