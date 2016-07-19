#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int mat[10][10];
    for(int i = 0; i < n; ++i)
    {
        mat[i][0] = 1;
        mat[0][i] = 1;
    }
    for(int y = 1; y < n; ++y)
    {
        for(int x = 1; x < n; ++x)
        {
            mat[x][y] = mat[x-1][y] + mat[x][y-1];
        }
    }
    cout << mat[n-1][n-1] << endl;
    return 0;
}
