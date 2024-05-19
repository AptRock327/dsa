#include <stdio.h>

unsigned int stepIndex = 1;

void hanoi(unsigned int n, char s, char a, char d)
{
	if(n == 0) return;
	if(n == 1)
	{
		printf("%d. %c goes to %c\n", stepIndex, s, d);
		stepIndex++;
		return;
	}
	hanoi(n-1, s, d, a);
	printf("%d. %c goes to %c\n", stepIndex, s, d);
	stepIndex++;
	hanoi(n-1, a, s, d);
	return;
}

int main(int argc, char** argv)
{
	unsigned int rings = 0;
	scanf("%u", &rings);
	hanoi(rings, 'A', 'B', 'C');
	return 0;
}
