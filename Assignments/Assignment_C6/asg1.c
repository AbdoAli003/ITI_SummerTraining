#include <stdio.h>

int main()
{
	int x, y, z;
	int *p, *q, *r;
	x = 2; y = 3; z = 4;
	p = &x; q = &y; r = &z;
	printf("x = %d\ny = %d\nz = %d\n\np = %p\nq = %p\nr = %p\n\n*p = %d\n*q = %d\n*r = %d\n",x,y,z,p,q,r,*p,*q,*r);
	printf("Swapping pointers...\n");
	r = p; p = q; q = r;
	printf("x = %d\ny = %d\nz = %d\n\np = %p\nq = %p\nr = %p\n\n*p = %d\n*q = %d\n*r = %d\n",x,y,z,p,q,r,*p,*q,*r);
	return 0;
}