#include <stdio.h>
#include <stdlib.h>
#include "Table.h"
#include "DLinkedList.h"
//���̺� �ʱ�ȭ
void TBLInit(Table* pt, HashFunc* f)
{
	//��� ���� �ʱ�ȭ
	for (int i = 0; i < MAX_TBL; i++)
	{
		ListInit(&(pt->tbl[i]));
	}

	pt->hf = f;
}

//���̺� Ű�� ���� ����
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot ns = { k,v };
	
	if (TBLSearch(pt, k) != NULL) // Ű�� �ߺ��Ǿ��ٸ�
	{
		printf("key �ߺ� ���� �߻�!\n");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns);
	}
}

//key�� �ٰŷ� ���̺��� ������ ����
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

//key�� �ٰŷ� ���̺��� ������ Ž��
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

