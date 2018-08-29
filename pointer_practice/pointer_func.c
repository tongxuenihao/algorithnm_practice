#include <stdio.h>

int (*match)(int *p1, int *p2);
int match_int(int *p1, int *p2)
{
	printf("%x   %x\n", *p1, *p2);
}

int main()
{
	int a = 1;
	int b = 2;
	match = match_int;
	match(&a, &b);
}