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
	BTreeNode* pNode = NULL; //부모 노드
	BTreeNode* cNode = *pRoot; //현재 노드
	BTreeNode* nNode = NULL; // 새로운 노드

	//새로운 노드가 추가될 위치를 찾는다.
	while (cNode != NULL)
	{
		if (data == GetData(cNode)) // 데이터의 중복을 허용하지 않음
			return;

		pNode = cNode;
		if (GetData(cNode) > data) // 왼쪽 서브 트리는 루트노드보다 작아야한다
		{
			cNode = GetLeftSubTree(cNode);
		}
		else // 오른쪽 서브 트리는 루트노드보다 커야한다.
			cNode = GetRightSubTree(cNode);
	}

	// pNode 의 자식 노드로 추가할 새 노드 생성
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	// pNode 의 자식 노드로 새 노드 추가
	if (pNode != NULL) // 새 노드가 루트 노드가 아니라면
	{
		if (data < GetData(pNode))
		{
			MakeLeftSubTree(pNode, nNode);
		}
		else
			MakeRightSubTree(pNode, nNode);
	}
	else // 새 노드가 루트 노드라면
	{
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst; //현재 노드
	BSTData cd; //현재 데이터

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode; //탐색 완료시 cNode의 주소값 반환 -> 이후 BSTGetNodeData로 target 출력
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);

	}
	return NULL; //탐색 대상이 저장되어 있지 않음(즉, target이 트리 안에 없다)

}
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode(); //가상 루트 노드
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;

	ChangeRightSubTree(pVRoot, *pRoot); //루트 노드를 pVRoot가 가르키는 노드의 오른쪽 자식 노드가 되게 한다.

	//탐색
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	//target이 트리에 존재하지 않으면 NULL값 반환
	if (cNode == NULL)
		return NULL;
	
	dNode = cNode;

	//삭제 노드가 단말 노드인 경우(Case 1)
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	//삭제 노드가 하나의 자식 노드를 가지고 있는 경우(case 2)
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; //삭제 노드의 자식 노드

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dcNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	//삭제 노드가 두 개의 자식 노드를 가지고 있는 경우(왼쪽,오른쪽)(case 3)
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode); //대체 노드를 가리킴(삭제노드 X)
		BTreeNode* mpNode = dNode; //대체 노드의 부모 노드를 가리킴
		int delData;

		//삭제 노드의 대체 노드를 찾는다.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제 노드에 대입한다
		delData = GetData(dNode); //대입 전 데이터 백업
		SetData(dNode, GetData(mNode)); //대입(저장)

		// 대체 노드의 부모 노드와 자식 노드를 연결
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData); //백업 데이터 복원.
	}

	//삭제된 노드가 루트 노드인 경우에 대한 추가처리!
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot); //루트 노드의 변경을 반영

	free(pVRoot); //가장 루트 노드의 소멸
	return dNode; //삭제 대상 반환
}
void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}