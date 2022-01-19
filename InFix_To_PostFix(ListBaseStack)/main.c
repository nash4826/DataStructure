#include <stdio.h>
#include "InfixToPostfix.h"

int main()
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);

	printf("%s \n", exp1);
	printf("%s \n", exp2);

	return 0;
}