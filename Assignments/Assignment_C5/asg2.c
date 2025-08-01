#include <stdio.h>
void swap(int* a, int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
int main()
{
	const int size = 10;
	int arr[size];
	int odd = 0, even = 0;
	for (int i = 0; i < size; i++)
	{
		printf("Enter number %d: ",i);
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < size; i++)
	{
		printf("number %d is ",arr[i]);
		if (arr[i] % 2){
			printf("an odd number\n");
			odd+=arr[i];
		}
		else {
			printf("an even number\n");
			even+=arr[i];
		}
	}
	printf("\nSum of odd numbers = %d\n",odd);
	printf("Sum of even numbers = %d",even);

	
	return 0;
}