#pragma once
#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define TRUE	1
#define FALSE	0
#define STACK_LEN	100

typedef int Data;

typedef struct _stack {
	Data stackArr[STACK_LEN];
	int topIdx;
}Stack;

void StackInIt(Stack* pstack);

int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);

Data SPop(Stack* pstack);

Data SPeek(Stack* pstack);

#endif // !__ARRAY_STACK_H__
