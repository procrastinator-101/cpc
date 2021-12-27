bool isPerfectSquare(int num)
{
    if (num == 1 || num == 0 || num == 4)
        return (1);
    if (num < 9)
        return (0);
    for (unsigned i = 9, j = 0; i <= num; j += 2)
    {
        if (i == num)
            return (1);
        i += 7 + j;
    }
    return (0);
}
