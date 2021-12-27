#include <stdio.h>
#include <stdlib.h>

int* countBits(int num, int* size)
{
    int *bits;
    
    *size = num + 1;
    bits = malloc(*size * sizeof(int));
	for (int i = 0; i < *size && i < 2; i++)
		bits[i] = i;
    for (int i = 2, k = 2; i < *size; k *= 2)
    {
		for (int j = 0; i < *size && j < k; i++, j++)
			bits[i] = bits[j] + 1;
    }
    return (bits);
}

int main()
{
	int *r;
	int size;
	
	r = (countBits(8, &size));

	for (int i = 0; i < size; i++)
		printf("%d ", r[i]);
	printf("\n");
	return (0);
}
