#include <cstdio>
#include <cmath>
int main()
{
    double total = 0;
    double numz = 0;
    for(int i = 0; i < 6; i++)
    {
        double x;
        scanf("%lf", &x);
        if(x > 0)
        {
            total += x;
            numz++;
        }
    }
    printf("%.0lf valores positivos\n%.1lf\n", numz, total/numz);
    return 0;
}
