#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
    int x;
    int y;
    cin >> y >> x;
    int mat[x][y];
    for(int i = 0; i < y; ++i)
        for(int j = 0; j < x; ++j)
            scanf("%d", &mat[j][i]);
    int maxx = 0;
    for(int y1= 0; y1 < y ; y1++)
    {
        for(int x1 = 0; x1 < x; ++x1)
        {
            if(mat[x1][y1] == 1)
            {
                if(y1 == 0 && x1 > 0)
                {
                    mat[x1][y1] = mat[x1-1][y1] + 1;
                    if(mat[x1][y1] > maxx)
                        maxx = mat[x1][y1];
                }
                else if(y1 > 0 && x1 > 0)
                {
                    int a = max(mat[x1-1][y1] + 1, mat[x1][y1-1] + 1);
                    mat[x1][y1] = a;
                    if(mat[x1][y1] > maxx)
                        maxx = mat[x1][y1];
                }
                else if(y1 > 0 && x1 == 0)
                {
                    mat[x1][y1] = mat[x1][y1-1]+1;
                    if(mat[x1][y1] > maxx)
                        maxx = mat[x1][y1];
                }
            }
        }
    }
    for(int y2 = 0; y2 < y; ++y2)
    {
        for(int x2 = x-1; x2 >= 0; --x2)
        {
            if(mat[x2][y2] == 1)
            {
                if(y2 == 0 && x2 < x-1)
                {
                    mat[x2][y2] = mat[x2+1][y2] + 1;
                    if(mat[x2][y2] > maxx)
                        maxx = mat[x2][y2];
                }
                if(y2 > 0 && x2 < x-1)
                {
                    mat[x2][y2] = max(mat[x2+1][y2] + 1, mat[x2][y2-1] + 1);
                    if(mat[x2][y2] > maxx)
                        maxx = mat[x2][y2];
                }
                else if(y1 > 0 && x2 == x-1)
                {
                    mat[x2][y2] = mat[x2][y2-1] +1;
                    if(mat[x2][y2] > maxx)
                        maxx = mat[x2][y2];
                }
            }
        }
    }
    cout << maxx << endl;
    return 0;
}
