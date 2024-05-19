#include <stdio.h>
#include <stdbool.h>

bool isSorted(int* arr, unsigned int size)
{
	for(int i = 1; i < size; i++)
	{
		if(arr[i-1] > arr[i])
		{
			return false;
		}
	}
	return true;
}

void chlopski_rozum_sort(int* arr, unsigned int size)
{
	int tmp;
	while(!isSorted(arr, size))
	{
		for(int j = 1; j < size; j++)
		{
			if(arr[j] < arr[j-1])
			{
				tmp = arr[j-1];
				for(int k = j-1; k < size-1; k++)
				{
					arr[k] = arr[k+1];
				}
				arr[size-1] = tmp;
			}
		}
		for(int i = 0; i < size; i++) printf("%d ", arr[i]);
		printf("\n");
	}
}

int main()
{
	int a[] = {673, 2874, 9821, 2837, 2934, 1923, 203, 231, 123, 11, 19};
	chlopski_rozum_sort(a, sizeof(a)/4);
	return 0;
}
