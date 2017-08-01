#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#define MAXN 2001
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int arr[MAXN][MAXN] = {{0}};
        for(int y = 0; y < b.size(); ++y)
        {
            for(int x = 0; x < a.size(); ++x)
            {
                if(x == 0)
                    arr[x][y] = y;
                else if(y == 0)
                    arr[x][y] = x;
            }
        }
        for(int y = 1; y <= b.size(); ++y)
        {
            for(int x = 1; x <= a.size(); ++x)
            {
                if(a[x-1] == b[y-1])
                {
                    arr[x][y] = min(arr[x-1][y-1], min(arr[x-1][y] + 1, arr[x][y-1] + 1));
                }
                else
                    arr[x][y] = min(arr[x-1][y-1], min(arr[x-1][y], arr[x][y-1])) + 1;
            }
        }
        cout << arr[a.size()][b.size()] << endl;
    }
    return 0;
}
