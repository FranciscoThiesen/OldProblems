#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a;
    while(scanf("%d", &a) != EOF)
    {
        int nums[a];
        int cost;
        scanf("%d", &cost);
        for(int i = 0; i < a; ++i)
        {
            int q;
            scanf("%d",&q);
            nums[i] = q - cost;
        }
        int m = 0;
        int cur = 0;
        for(int j = 0; j < a; ++j)
        {
            if(cur < 0)
                cur = nums[j];
            else
                cur += nums[j];
            if(cur > m)
                m = cur;
        }
        cout << m << endl;
    }
    return 0;
}
