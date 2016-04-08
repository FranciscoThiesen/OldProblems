#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    double max = 8.0;
    int mat = -1;
    for(int i = 0; i < t; ++i)
    {
        int a;
        double b;
        cin >> a >> b;
        if(b >= max)
        {
            max = b;
            mat = a;
        }
    }
    if(mat == -1)
        cout << "Minimum note not reached"<< endl;
    else
        cout << mat << endl;

    return 0;
}
