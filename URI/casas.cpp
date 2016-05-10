#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int a = 1,b = 1,c= 1;
    while(a != 0)
    {
        cin >> a;
        if(!a)
            break;
        cin >> b >> c;
        double ans = floor(a*b*(100.0/c));
        printf("%.0f\n", sqrt(ans));
    }
    return 0;
}
