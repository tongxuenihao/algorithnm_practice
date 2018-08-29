#include <stdio.h>
int main()
{
	int a[10] = {0};
	int *ptr;
	ptr = a;
	*ptr = 5;
	printf("%02x\n",a[0]);
}