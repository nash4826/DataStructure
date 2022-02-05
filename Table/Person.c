#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p)
{
	return p->ssn;
}

void ShowPerInfo(Person* p)
{
	printf("�ֹε�Ϲ�ȣ : %d\n", GetSSN(p));
	printf("�̸� : %s \n �ּ� : %s\n", p->name, p->addr);

}

Person* MakePersonData(int ssn, char* name, char* addr)
{
	Person* newPerson = (Person*)malloc(sizeof(Person));
	newPerson->ssn = ssn;
	strcpy(newPerson->name, name);
	strcpy(newPerson->addr, addr);

	return newPerson;
}
