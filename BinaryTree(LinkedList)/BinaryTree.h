#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef void VisitFuncPrt(Data data);

typedef struct _bTreeNode {
	Data data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
Data GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, Data data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void PreorderTraverse(BTreeNode* bt, VisitFuncPrt action); //전위 순회
void InorderTraverse(BTreeNode* bt, VisitFuncPrt action); //중위 순회
void PostorderTraverse(BTreeNode* bt, VisitFuncPrt action); //후위 순회

void DeleteTree(BTreeNode* bt);

#endif