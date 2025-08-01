#include <stdio.h>

int nPr(int, int);
int fact(int);

int main()
{
	int n, r;
	printf("Enter the vaule of n and r: ");
	scanf("%d %d",&n,&r);
	if (n < 0 || r < 0)
	{
		printf("n, r must be positive!");
		return 0;
	}
	if (n < r)
	 {
		printf("n must be greater than r!");
		return 0;
	 }
	printf("%dP%d = %d\n",n,r,nPr(n,r));
    
	return 0;
}
int fact(int n)
{
	if (n == 0) 
		return 1;
	int f = 1;
	for (int i = 1; i <= n; i++)
	{
		f*=i;
	}
	return f;
		
}
int nPr(int n , int r)
{
	return fact(n) / fact(n-r);
}
