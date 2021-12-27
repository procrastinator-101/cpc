#include <stdio.h>

double findMedianSortedArrays(int *a, int n, int *b, int m)
{
	int i, j, k, l, h, s;

	s = (n + m) / 2 + 1;
	l = n ? a[0] : b[0];
	printf("s = %d\n", s);

    for (i = 0, j = 0, k = 0, h = l; i < n && j < m && k <= s; k++)
	{
		if (a[i] < b[j])
		{
			l = h;
			h = a[i++];
		}
		else
		{
			l = h;
			h = b[j++];
		}
		printf("k = %d\ti = %d\tj = %d\tl = %d\th = %d\n", k, i, j, l, h);
	}
	printf("++k = %d\tl = %d\th = %d\n", k, l, h);
	if (k < s)
	{
		if (k < s - 1)
		{
			l = i < n ? a[s - k - 1 - !m] : b[s - k - 1 - !n];
			h = i < n ? a[s - k - !m] : b[s - k - !n];
		}
		else
		{
			l = h;
			h = i < n ? a[s - k - 1] : b[s - k - 1];
		}
	}
	printf(">>k = %d\tl = %d\th = %d\n", k, l, h);
	printf("n = %d\tm = %d\n", n, m);
	if ((n + m) % 2)
		return (h);
	return ((h + l) / 2.0);
}

int main()
{
	int n;
	int m;
	int a[] = {1,1,3,3};
	int b[] = {1,1,3,3};

	n = sizeof(a) / sizeof(int);
	m = sizeof(b) / sizeof(int);
	printf("r = %f\n", findMedianSortedArrays(a, n, b, m)); 

}
