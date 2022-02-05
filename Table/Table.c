#include <stdio.h>
#include <stdlib.h>
#include "Table.h"
#include "DLinkedList.h"
//테이블 초기화
void TBLInit(Table* pt, HashFunc* f)
{
	//모든 슬롯 초기화
	for (int i = 0; i < MAX_TBL; i++)
	{
		ListInit(&(pt->tbl[i]));
	}

	pt->hf = f;
}

//테이블에 키와 값을 저장
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot ns = { k,v };
	
	if (TBLSearch(pt, k) != NULL) // 키가 중복되었다면
	{
		printf("key 중복 오류 발생!\n");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns);
	}
}

//key를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			LRemove(&(pt->tbl[hv]));
			return cSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					LRemove(&(pt->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}
	return NULL;
	
}

//key를 근거로 테이블에서 데이터 탐색
Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;
	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			return cSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					return cSlot.val;
				}
			}
		}
	}
	return NULL;

}

