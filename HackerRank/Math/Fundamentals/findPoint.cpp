#include<cstdio>
#include<iostream>
#include <cmath>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; ++i)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d %d", x2 + (x2 - x1), y2 + (y2-y1));
    }
    return 0;
}
