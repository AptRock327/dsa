#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ARR_SIZE 12

void shuffleArray(int* arr)
{
	int tmp;
	int swap;
	for(int i = 0; i < ARR_SIZE; i++)
	{
		swap = rand() % ARR_SIZE;
		tmp = arr[0];
		arr[0] = arr[swap];
		arr[swap] = tmp;
	}
}

bool isSorted(int* arr)
{
	for(int i = 1; i < ARR_SIZE; i++)
	{
		if(arr[i-1] > arr[i])
		{
			return false;
		}
	}
	return true;
}

void bogoSort(int* arr)
{
	while(!isSorted(arr))
	{
		shuffleArray(arr);
		for(int i = 0; i < ARR_SIZE; i++) printf("%d ", arr[i]);
		printf("\n");
	}
}

int main()
{
	srand(time(0));
	int a[] = {5, 7, 3, 2, 8, 13, 9, 1, 18, 15, 2, 0};
	bogoSort(a);
	for(int i = 0; i < ARR_SIZE; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
