#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        double ans = (d-b)/(c-a);
        int ans1 = ans;
        int ans2 = (int) (100*((double)(ans - ans1)));
        if(ans2 == 0)
            printf("%d,00\n",ans1);
        else
            printf("%d,%d\n", ans1, ans2);
    }
    return 0;
}
