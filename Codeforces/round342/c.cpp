#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main()
{
    int n, col;
    scanf("%d%d", &n, &col);
    int max = n*n;
    int mat[n-1][n-1];
    vector<int> remaining;
    for(int j = 1; j <= n*(n-col-1); j++)
        remaining.push_back(j);
    int famb = 0;
    int total = 0;
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {   
            if(x < col-1)
            {
                mat[x][y] = remaining[famb];
                famb++;
            }
            else if(x == col-1)
            {
                if(y == 0)
                {
                    mat[x][y] = max - (n-col);
                    total += mat[x][y];
                }
                else
                {
                    mat[x][y] = mat[x][y-1] - (n-col) - 1;
                    total += mat[x][y];
                }
            }
            else
            {
                mat[x][y] = mat[x-1][y] + 1;
            }
        }
    }
    cout << total << endl;
    for(int y1 = 0; y1 < n; y1++)
    {
        for(int x1 = 0; x1 < n; x1++)
        {
            cout << mat[x1][y1] << " ";
        }
        cout << endl;
    }
    return 0;
}
