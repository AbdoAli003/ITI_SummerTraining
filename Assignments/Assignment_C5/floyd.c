#include <stdio.h>

void printFloyd(int y, int x, int i, int n)
{
	if (y == n + 1)
		return;
	if ()
	
	int x = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d ",x++);
		}
		printf("\n");
	}
}

int main()
{
	int n;
	printf("Enter number of rows: ");
	scanf("%d",&n);
    printFloyd(1,1,1,n);

	
	return 0;
}