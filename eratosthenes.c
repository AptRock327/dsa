#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv)
{
	int n = 0;
	if(argc > 1)
    		n = strtol(argv[1], (char **) NULL, 10);
	printf("Starting to find all primes up to %d\n", n);
	bool* isPrime = malloc(n-1);
	for(int i = 0; i < n-1; i++)
	{
		isPrime[i] = true;
	}
	for(int i = 2; i < n+1; i++)
	{
		if(isPrime[i-2]) printf("%d\n", i);
		for(int j = i-2; j < n-1; j+=i)
		{
			isPrime[j] = false;
		}
	}
	free(isPrime);
	return 0;
}
