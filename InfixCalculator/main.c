#include <stdio.h>
#include "InfixCalculator.h"

int main()
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	

	printf("%s = %d\n", exp1,EvalInfixExp(exp1));
	printf("%s = %d\n", exp2, EvalInfixExp(exp2));

	return 0;
}