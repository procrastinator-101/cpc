#include <stdio.h>

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
{
	int	a;
	int	b;

	if (coordinates[0][0] == coordinates[1][0] && coordinates[0][1] != coordinates[1][1])
		return (1);
	a = (coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
	b = coordinates[0][1] - a * coordinates[0][0];
	for (int i = 2; i < coordinatesSize; i++)
		if (coordinates[i][1] != a * coordinates[i][0] + b)
			return (0);
	return (1);
}

int main()
{
}
