#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* merge(int* a, int* b, unsigned int size_a, unsigned int size_b)
{
	int* result = malloc((size_a+size_b+1)*4);
	for(int i = 0; i < size_b; i++) result[i] = b[i];
	int aux = size_b;
	bool isPresent;
	for(int i = 0; i < size_a; i++)
	{
		isPresent = false;
		for(int j = 0; j < aux; j++)
		{
			if(a[i] < result[j])
			{
				for(int k = aux; k > j; k--)
				{
					result[k] = result[k-1];
				}
				result[j] = a[i];
				aux++;
				isPresent = true;
				break;
			}
		}
		if(!isPresent)
		{
			result[aux] = a[i];
			aux++;
		}
	}
	return result;
}

int* merge_sort(int* arr, unsigned int size)
{
	int* result = malloc(8);
	if(size < 2)
	{
		result[0] = arr[0];
		return result;
	}
	int* a = merge_sort(arr, size/2);
	int* b;
        if(size % 2) b = merge_sort(arr+(size/2), (size/2)+1);
	else b = merge_sort(arr+(size/2), size/2);
	free(result);
	if(size % 2) result = merge(a, b, size/2, (size/2)+1);
	else result = merge(a, b, size/2, size/2);
	free(a);
	free(b);
	return result;
}

int main(int argc, char** argv)
{
	int a[] = {78, 92, 31, 23, 74};
	int* c = merge_sort(a, sizeof(a)/4);
	for(int i = 0; i < sizeof(a)/4; i++) printf("%d ", c[i]);
	printf("\n");
	return 0;
}
