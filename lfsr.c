#include <stdio.h>
#include <math.h>
#include <time.h>

unsigned int lfsr = 0;

void lfsr_srand(unsigned int seed)
{
	lfsr = seed;
}

unsigned int lfsr_rand()
{
	unsigned int intResult = 0;
	unsigned int bitResult = 0;
	for(int i = 0; i < 32; i++)
	{
        	bitResult = lfsr % 2;
		intResult|=(bitResult<<i);
		lfsr>>=1;
		lfsr|=((bitResult ^ (lfsr % 2))<<31);
	}
	return intResult;
}

int main()
{
	lfsr_srand(time(0));
	for(int i = 0; i < 100; i++) printf("%u\n", lfsr_rand() % 10);
	return 0;
}
