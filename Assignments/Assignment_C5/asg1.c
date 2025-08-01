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
	int swapped;
	for (int i = 0; i < size; i++)
	{
		printf("Enter number %d: ",i);
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapped = 1;
			} 
			
		}
		if (!swapped) break;
	}
		for (int i = 0; i < size; i++)
		printf("%d ",arr[i]);
	printf("\nThe minimum number is %d\n",arr[0]);
	printf("The maximum number is %d\n",arr[size-1]);
	
	return 0;
}