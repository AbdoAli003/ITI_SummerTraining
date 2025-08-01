#include <stdio.h>

int main()
{
	float a,b;
	int op; // operation number
	
	printf("Enter the two numbers: ");
	scanf("%f %f",&a,&b);
	printf("\nChose the operand:\n");
	printf("\n1- addition\n2- subtraction\n3- multiplication\n4- division\n\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
		printf("\na + b = %f",a+b);
		break;
		case 2:
		printf("\na - b = %f",a-b);
		break;
		case 3:
		printf("\na * b = %f",a*b);
		break;
		case 4:
		printf("\na / b = %f",a/b);
		break;
		default:
		printf("\nUnvalid choice!");
	}
	return 0;
}