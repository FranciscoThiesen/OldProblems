#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double p = (a+b+c);
    if(a + b > c && b + c > a && a + c > b)
        printf("Perimetro = %.1lf\n", p);
    else
        printf("Area = %.1lf\n", (a+b)/2*c);
    return 0;
}
