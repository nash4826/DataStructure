#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BinaryTree3.h" //트리의 구조를 확인하기 위해서 불러옴
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* avlRoot;
	BTreeNode* clNode; //current left node
	BTreeNode* crNode; //current right node

	BSTMakeAndInit(&avlRoot);

	/*

	//1~9까지 순서대로 값을 저장한다.
	//만약 리밸런싱을 하지 않는 다면 오른쪽 방향으로만 노드가 추가 되는
	//비대칭 구조의 트리가 형성 된다. 리밸런싱이 된다면 RR회전의 결과만 확인할 수 있다. 

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

	
	//LR상태의 연출
	/*
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	
	printf("Root Node : %d \n", BSTGetNodeData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);

	printf("left : %d, right : %d \n", GetData(clNode), GetData(crNode));
	*/

	//RL상태의 연출
	
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);

	printf("Root Node : %d \n", BSTGetNodeData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);

	printf("left : %d, right : %d \n", GetData(clNode), GetData(crNode));
	
	return 0;
}