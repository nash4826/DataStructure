#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newNode = malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Data GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, Data data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPrt action)
{
	if (bt == NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPrt action)
{
	if (bt == NULL)
		return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);

}
void PostorderTraverse(BTreeNode* bt, VisitFuncPrt action)
{
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("Deleter Complete! -> Del data = %d\n", bt->data);
	free(bt);
}