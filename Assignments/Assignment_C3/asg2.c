#include <stdio.h>
#include <string.h>

int main()
{
	int num;
	printf("Enter a number: ");
	scanf("%d",&num);
	if (num == 0)
	{
		printf("Enter a non-zero number!");
	}
	int tmp = (num < 0) ? -num : num;
	for (int i = 1; i <= tmp; i++)
	{
		printf("%d * %d = %d\n",num,i,num*i);
	}
	
	return 0;
}