#include <stdio.h>

int gcd(int a, int b)
{
	if(!b) return a; return gcd(b, a % b);
}

int main()
{
	printf("%d\n", gcd(55, 10));
	return 0;
}
