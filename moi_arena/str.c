#include <iostream>

using namespace std;

int main()
{
    int t;
    
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
        if (n > 4)
            cout << 0 << endl;
        else if (n == 4)
            cout << 4 << endl;
        else if (n == 3)
            cout << 6 << endl;
        else if (n == 2)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    return (0);
}
