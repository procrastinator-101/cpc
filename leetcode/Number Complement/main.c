#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int findComplement(int num)
{
	int			msb;	
	unsigned	r;

	r = ~num;
	for (msb = 0; num; msb++)
		num >>= 1;
	r = r << (32 - msb) >> (32 - msb);
    return (r);
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("r = %d\n", findComplement(num));
	return (0);
}
