#include <stdio.h>
#include <stdbool.h>

bool binary_search(int* arr, unsigned int size, int value)
{	
	if(arr[size>>1] == value) return true;
	if(size == 1) return false;
	else if(arr[size-1] == value) return true; 
	if(arr[size>>1] < value) binary_search(arr+(size>>1), size>>1, value);
	else binary_search(arr, size>>1, value);
}

int main()
{
	int a[] = {1, 3, 4, 5, 8, 9, 10, 15, 18, 22, 73};
	if(binary_search(a, sizeof(a)/4, 15)) printf("Found\n");
	else printf("Not found\n");

	return 0;
}
