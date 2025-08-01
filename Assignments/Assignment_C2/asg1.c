#include <stdio.h>

int main()
{
	int x,y,z;
	printf("Please enter three numbers: ");
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	int great;
	if (x > y)
	{
		great = x;
		if (great < z)
			great = z;
	}
	else 
	{
		great = y;
		if (great < z)
			great = z;
	}
	printf("The greatest number = %d",great);
	return 0;
}