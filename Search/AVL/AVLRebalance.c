#include <stdio.h>
#include "BinaryTree3.h"

//LL회전
BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// cNode의 오른쪽 서브 트리(공집합)을 pNode의 왼쪽 서브 트리와 교체
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode)); 
	ChangeRightSubTree(cNode, pNode); //LL 회전

	return cNode; // 리밸런싱 이후 cNode는 pNode가 되었기 때문에 cNode 주소값 반환
}

//RR회전
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

//RL 회전
BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode)); //부분적 LL회전
	return RotateRR(pNode); //RR회전
}

//LR 회전
BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

//트리의 높이를 계산하여 반환

int GetHeight(BTreeNode* bst)
{
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	//왼쪽 서브 트리 높이 계산
	leftH = GetHeight(GetLeftSubTree(bst));
	//오른쪽 서브 트리 높이 계산
	rightH = GetHeight(GetRightSubTree(bst));

	//큰 값의 높이를 반환
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}


// 두 서브 트리의 높이의 차를 반환(균형 인수 함수)
int GetHeightDiff(BTreeNode* bst)
{
/*
	균형 인수 = 왼쪽 서브 트리의 높이 - 오른쪽 서브 트리의 높이
	AVL 트리는 균형 인수의 절대값이 2 이상인 경우 리밸런싱에 들어간다.
*/
	int lsh; //left sub tree height
	int rsh; //right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
	
}

//리밸런싱
BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if (hDiff > 1) //왼쪽 서브 트리 방향으로 높이가 2 이상인 경우
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	if (hDiff < -1) // 오른쪽 서브 트리 방향으로 높이가 2 이상인 경우
	{
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;
}