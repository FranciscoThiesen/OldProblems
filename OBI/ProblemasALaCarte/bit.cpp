#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 1;
    int t = 1;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        int ans;
        for(int i = 0; i < n; ++i)
        {
            int a;
            scanf("%d", &a);
            if(a == i+1)
            {
                ans = a;
            }
        }
        printf("Teste %d\n%d\n\n",t, ans);
        t++;
    }
    return 0;
}
