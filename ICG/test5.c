#include <stdio.h>

void main()
{
	int a,b,c,d;

	a = d * b + c;
	b = (b-c)*d + (b-c)*d;
	c = b+c*d;
	d = b*(c) + b*(c);
	if (a<3)
	{
		if(c<d)
		{
		a = 98;
		}
		else
		{
		a = d * b + c;
		}
	}
	else
	{
		a++;
	}
}
