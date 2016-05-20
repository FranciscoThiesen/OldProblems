#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char arr[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            char f;
            cin >> f;
            arr[j][i] = f;
        }
    }

    for(int y = 1; y < n-1;++y)
    {
        for(int x = 1; x < n-1; ++x)
        {
            int val = arr[x][y] - '0';
            if(arr[x][y+1] != 'X' && arr[x-1][y] != 'X' && arr[x][y-1] != 'X' && arr[x+1][y] != 'X')
            {
                if(arr[x][y+1] - '0' <  val  && arr[x-1][y]-'0' < val && arr[x][y-1] -'0' < val && arr[x+1][y] - '0' < val)
                        arr[x][y] = 'X';
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << arr[j][i] ;
        cout << endl;
    }


}
