#include <stdio.h>
#include "BinarySearchTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL; //�θ� ���
	BTreeNode* cNode = *pRoot; //���� ���
	BTreeNode* nNode = NULL; // ���ο� ���

	//���ο� ��尡 �߰��� ��ġ�� ã�´�.
	while (cNode != NULL)
	{
		if (data == GetData(cNode)) // �������� �ߺ��� ������� ����
			return;

		pNode = cNode;
		if (GetData(cNode) > data) // ���� ���� Ʈ���� ��Ʈ��庸�� �۾ƾ��Ѵ�
		{
			cNode = GetLeftSubTree(cNode);
		}
		else // ������ ���� Ʈ���� ��Ʈ��庸�� Ŀ���Ѵ�.
			cNode = GetRightSubTree(cNode);
	}

	// pNode �� �ڽ� ���� �߰��� �� ��� ����
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	// pNode �� �ڽ� ���� �� ��� �߰�
	if (pNode != NULL) // �� ��尡 ��Ʈ ��尡 �ƴ϶��
	{
		if (data < GetData(pNode))
		{
			MakeLeftSubTree(pNode, nNode);
		}
		else
			MakeRightSubTree(pNode, nNode);
	}
	else // �� ��尡 ��Ʈ �����
	{
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst; //���� ���
	BSTData cd; //���� ������

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode; //Ž�� �Ϸ�� cNode�� �ּҰ� ��ȯ -> ���� BSTGetNodeData�� target ���
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);

	}
	return NULL; //Ž�� ����� ����Ǿ� ���� ����(��, target�� Ʈ�� �ȿ� ����)

}
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode(); //���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;

	ChangeRightSubTree(pVRoot, *pRoot); //��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.

	//Ž��
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	//target�� Ʈ���� �������� ������ NULL�� ��ȯ
	if (cNode == NULL)
		return NULL;
	
	dNode = cNode;

	//���� ��尡 �ܸ� ����� ���(Case 1)
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	//���� ��尡 �ϳ��� �ڽ� ��带 ������ �ִ� ���(case 2)
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; //���� ����� �ڽ� ���

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dcNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	//���� ��尡 �� ���� �ڽ� ��带 ������ �ִ� ���(����,������)(case 3)
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode); //��ü ��带 ����Ŵ(������� X)
		BTreeNode* mpNode = dNode; //��ü ����� �θ� ��带 ����Ŵ
		int delData;

		//���� ����� ��ü ��带 ã�´�.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// ��ü ��忡 ����� ���� ���� ��忡 �����Ѵ�
		delData = GetData(dNode); //���� �� ������ ���
		SetData(dNode, GetData(mNode)); //����(����)

		// ��ü ����� �θ� ���� �ڽ� ��带 ����
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData); //��� ������ ����.
	}

	//������ ��尡 ��Ʈ ����� ��쿡 ���� �߰�ó��!
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot); //��Ʈ ����� ������ �ݿ�

	free(pVRoot); //���� ��Ʈ ����� �Ҹ�
	return dNode; //���� ��� ��ȯ
}
void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}