#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int t;
    int test = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, jmp;
        scanf("%d %d", &n, &jmp);
        vector<int> arr(n, 1);
        int ans;
        int cur = jmp-1;
        int start = jmp-1;
        arr[jmp-1] = 0;
        cout << jmp-1 << endl;
        int kills = 1;
        while(kills < n-1)
        {
            int pulo = jmp-1;
            for(int i = start; i < n; ++i)
            {
                if(arr[i] == 1 && pulo != 0)
                    pulo--;
                else if(pulo == 0)
                {
                    if(arr[i])
                    {
                        arr[i] = 0;
                        kills++;
                        pulo = jmp-1;
                    }
                }
                if(kills == n-1)
                    break;
                if(i == n-1)
                {
                    i = -1;
                }
            }
        }
        for(int i = 0; i < n; ++i)
            if(arr[i])
                printf("Case %d: %d\n", test, i+1);
        test++;
        
    }
    return 0;
}
