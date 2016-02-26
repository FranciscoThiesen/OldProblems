#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        double a,b,c;
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("%.1lf\n",((a*2) + (b*3) + (c*5))/10);
    }
    return 0;
}
