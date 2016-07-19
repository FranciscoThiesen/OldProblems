#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    double a, b;
    while(scanf("%lf %lf", &a, &b) != EOF)
    {
        if(b == 0)
            cout << 0 << endl;
        else
        {
            double acc = a/b;
            printf("%.0lf\n", (acc*4.0*b*b)/2.0);
        }
    }
    return 0;
}
