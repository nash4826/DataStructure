#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
int main()
{
	BTreeNode* bstRoot;
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	//트리 출력(자동 정렬)
	BSTShowAll(bstRoot);
	printf("\n");
	//탐색
	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("Search fail\n");
	else
		printf("Search key : %d\n", BSTGetNodeData(sNode));

	//삭제 및 출력
	sNode = BSTRemove(&bstRoot, 3);
	free(sNode);
	BSTShowAll(bstRoot);

	
	return 0;
}