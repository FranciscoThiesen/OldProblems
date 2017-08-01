#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

int mat[1001][50] = {0};
int weight[51];
int value[51];
int main()
{
    int maxWeight = 1;
    int numS = 1;
    int inc = 1;
    while(maxWeight + numS > 0)
    {
        memset(weight, 0, sizeof weight);
        memset(value, 0, sizeof value);
        scanf("%d%d",&maxWeight, &numS);
        if(numS == 0)
            return 0;
        for(int i = 0; i < numS;i++)
        {
            int w,v;
            scanf("%d%d", &w, &v);
            weight[i] = w;
            value[i] = v;
        }
        for(int y = 0; y < numS; ++y)
        {
            for(int x = 0;x <= maxWeight;++x)
            {
                if(y== 0)
                {
                    if(weight[y] <= x)
                    {
                        mat[x][y] = max(0,value[y]);
                    }
                    else
                    {
                        mat[x][y] = 0;
                    }
                }
                else
                {
                    if(weight[y] <= x)
                        mat[x][y] = max(mat[x-weight[y]][y-1] + value[y], mat[x][y-1]);
                    else
                        mat[x][y] = mat[x][y-1];
                }
            }
        }
        cout << "Teste " << inc << endl << mat[maxWeight][numS-1] << endl << endl;
        inc++;
    }
    return 0;
}
        
