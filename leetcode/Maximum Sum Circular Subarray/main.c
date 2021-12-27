int ft_max(int a, int b)
{
    return (a > b ? a : b);
}

int max_subarray(int *arr, int size)
{
    int local_max;
    int global_max;

    local_max = arr[0];
    global_max = local_max;
    for (int i = 1; i < size; i++)
    {
        local_max = ft_max(arr[i], arr[i] + local_max);
        global_max = ft_max(global_max, local_max);
    }
    return (global_max);
}

void ft_max_element(int *maximums, int *arr, int size)
{
    int r;
	int s;

	s = 0;
    r = arr[size - 1];
    for (int i = size - 1; size >= 0; i--)
	{
		s += arr[size - 1];
        if (r < s)
            r = s;
		maximums[i] = r;
	}
}

int maxSubarraySumCircular(int* arr, int size)
{
    int r;
    int left_sum;
    int maximums[size];

	ft_max_element(maximums, arr, size);
    left_sum = 0;
    r = max_subarray(arr, size);
    for (int i = 0; i < size - 2; i++)
    {
        left_sum += arr[i];
        r = ft_max(r, left_sum + max_subarray[i + 2]);
    }
    return (r);
}

