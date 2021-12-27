#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

// This makes the sort be according to column 2 and ascending
bool sortFunc( const vector<int>& p1, const vector<int>& p2 )
{
	return p1[1] < p2[1];
}

void	display(const vector<vector<int>>& v)
{
	for( int i = 0 ; i < v.size(); i++ )
	{
		for( int j = 0 ; j < v[i].size(); j++ )
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

  srand(time(NULL));

  // Creates and initializes 10 x 4 vector
	vector< vector<int> > vec;

	for( int i=0; i<100; i++ )
	{
		vector<int> tmpVec;

		for( int j=0; j<2; j++ )
		{
			tmpVec.push_back( rand()%100 );
		}
		vec.push_back( tmpVec );
	}

	// Print out the pre-sorted vector
	cout << "Pre-sorting state:" << endl;
	display(vec);

	// Do the sorting according to column 2
	sort(vec.begin(), vec.end(), sortFunc);

	// Print out the post-sorted vector
	cout << "Post-sorting state:" << endl;
	display(vec);

	return 0;
}