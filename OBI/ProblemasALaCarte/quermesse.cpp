#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n = 1;
    int t = 1;
    int a;
    while(scanf("%d", &n) != 0)
    {
        if(!n)
            return 0;
        cin >> a;
        for(int i = 1; i <= n; ++i)
        {
            if(a == i)
            {
                printf("Teste %d\n%d\n", t,a);
                break;
            }
        }
    }
    t++;
    return 0;
}

