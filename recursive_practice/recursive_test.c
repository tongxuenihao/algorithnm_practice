#include <stdio.h>

int recursive_test(int n)
{
	if(n < 0)
		return -1;
	else if(n ==0 || n == 1)
		return 1;
	else
		return n*recursive_test(n-1);
}

int main()
{
	int data;
	data = recursive_test(5);
	printf("%d\n", data);
}