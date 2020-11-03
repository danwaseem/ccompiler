#include<stdio.h>

int main()
{
	int x = 5;
	while(x>0)
	{
		printf("How are you?");
		x--;
	}

	x=4;
	while(x>0)
	{
		printf("%d",x);
		x--;
		int y;
		y= 4;
		while(y>0)
		{
			printf("%d", y);
			y--;
		}
	}
}
