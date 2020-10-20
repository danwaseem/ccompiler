// exmaple of duplication C assigned twice

#include <stdio.h>

void increment(int C)
{
	int C = 1;
	int A = 12;
	A = A + C;
	printf("%d",C);

}

void main()
{
	int C = 2;
	C = 4;
	increment(C);
	printf("%d", C);
}
