#include <stdio.h>
#define MAX_SIZE 100
void swap(int* a, int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void scanArrayLoop(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter element %d: ",i);
		scanf("%d",arr+i);
	}
}
void sort(int* arr, int size)
{
	int swapped;
	for (int i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(arr+j) > *(arr+j+1))
			{
				swap(arr+j,arr+j+1);
				swapped = 1;
			} 
		}
		if (!swapped) break;
	}
}
void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",*(arr+i));
	}
}

int main()
{
	int arr[MAX_SIZE];
	int n;
	printf("Enter the size of the array (max %d): ",MAX_SIZE);
	scanf("%d",&n);
	if (n < 1 || n > MAX_SIZE)
	{
		printf("Invalid size of array!");
		return 1;
	}
	scanArrayLoop(arr,n);
	sort(arr,n);
	printf("The array after sort: \n");
	print(arr,n);
	return 0;
}