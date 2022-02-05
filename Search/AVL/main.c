#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BinaryTree3.h" //Ʈ���� ������ Ȯ���ϱ� ���ؼ� �ҷ���
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* avlRoot;
	BTreeNode* clNode; //current left node
	BTreeNode* crNode; //current right node

	BSTMakeAndInit(&avlRoot);

	/*

	//1~9���� ������� ���� �����Ѵ�.
	//���� ���뷱���� ���� �ʴ� �ٸ� ������ �������θ� ��尡 �߰� �Ǵ�
	//���Ī ������ Ʈ���� ���� �ȴ�. ���뷱���� �ȴٸ� RRȸ���� ����� Ȯ���� �� �ִ�. 

	for (int i = 1; i < 10; i++) 
		BSTInsert(&avlRoot, i); 
	

	printf("Root Node : %d \n", BSTGetNodeData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("left 1 : %d, right 1 : %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("left 2: %d, right2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("left 3: %d, right 3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("left 4: %d, right 4: %d \n", GetData(clNode), GetData(crNode));

	*/

	
	//LR������ ����
	/*
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	
	printf("Root Node : %d \n", BSTGetNodeData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);

	printf("left : %d, right : %d \n", GetData(clNode), GetData(crNode));
	*/

	//RL������ ����
	
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);

	printf("Root Node : %d \n", BSTGetNodeData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);

	printf("left : %d, right : %d \n", GetData(clNode), GetData(crNode));
	
	return 0;
}