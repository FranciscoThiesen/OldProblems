#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int a = 1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int value[101] = {0};
        int weight[101] = {0};
        int arr[51][101] = {{0}};
        int used = 0;        
        for(int i = 0; i < n; ++i)
        {
            int V, W;
            scanf("%d %d", &V, &W);
            value[i] = V;
            weight[i] = W;
        }
        if(n == 1 && weight[0] <= 50)
            used = n;
        int left = 0;
        int wM = 0;
        int mx = 0;
        int unused = 0;
        for(int y = 0; y < n; ++y)
        {
            for(int x = 0; x < 51; ++x)
            {
                if(y == 0)
                {   if(weight[y] <= x)
                        arr[x][y] = max(0, value[y]);
                    else
                        arr[x][y] = 0;
                    if(arr[x][y] > mx)
                    {
                        mx = arr[x][y];
                        wM = x;
                    }
                }
                else
                {
                    if(weight[y] <= x)
                    {
                        arr[x][y] = max(arr[x - weight[y]][y-1] + value[y], arr[x][y-1]);
                    }
                    else
                        arr[x][y] = arr[x][y-1];
                    if(arr[x][y] > mx)
                    {
                        mx = arr[x][y];
                        wM = x;
                    }
                }
            }
        }
        int num = arr[50][n-1];
        int y = n-1;
        int x = 50;
        while(num > 0)
        {               
            if(num > arr[x][y-1] && num > arr[x-1][y])
            {
                used++;
                x-= weight[y];
                y--;
            }
            num = arr[x][y];
            if(num == value[0] || num == 0)
                break;
            if(num == arr[x][y-1])
                y--;
            else if(num == arr[x-1][y])
                x--;


        }
        if(a != 1)
            cout << endl << arr[50][n-1] << " brinquedos" << endl << "Peso: " << wM << " kg" << endl << "sobra(m) " << max(n-used,0)  << " pacote(s)" <<  endl;
        else
            cout << arr[50][n-1] << " brinquedos" << endl << "Peso: " << wM << " kg" << endl << "sobra(m) " << max(n-used,0)  << " pacote(s)" <<  endl;
    a++;
    }
    return 0;
}
