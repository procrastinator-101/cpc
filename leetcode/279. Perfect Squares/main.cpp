#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <strings.h>
#include <utility>
#include <vector>
using namespace std;

int mycount;

int sumLength(int* squares, int* targets, int target, int maxCandidate, int len)
{
	if (targets[target])
		return len + targets[target];

	int tmp;
	int ret = 100;
	int* it = lower_bound(squares, squares + maxCandidate + 1, target);


	cout << "target : " << target << endl;
	cout << "maxCandidate : " << maxCandidate << endl;
	if (it != squares + maxCandidate + 1)
		maxCandidate = it - squares;
	cout << "--maxCandidate : " << maxCandidate << endl;
	for (int i = maxCandidate; i > 0; i--)
	{
		if (squares[i] == target)
		{
			targets[target] = 1;
			return len + 1;
		}
	}
	for (int i = maxCandidate; i > 0; i--)
	{
		if (squares[i] > target)
			continue;

		tmp = sumLength(squares, targets, target - squares[i], maxCandidate, len + 1);
		if (tmp == len + 2)
		{
			targets[target] = 2;
			return tmp;
		}
		if (tmp < ret)
			ret = tmp;
	}
	targets[target] = ret - len;
	return ret;
}

int numSquares(int n)
{
	int size = n / 2 + 2;
	int squares[size];
	int targets[n + 1];
	mycount = n;
	bzero(targets, sizeof(targets));
	for (int i = 0; i < size; i++)
		squares[i] = i * i;
	int ret = sumLength(squares, targets, n, size, 0);
	for (int i = 0; i < n + 1; i++)
		cout << "target : " << i << " distance : " << targets[i] << endl;
	return ret;
}

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		cout << numSquares(atoi(argv[1])) << endl;
	}

	return 0;
}