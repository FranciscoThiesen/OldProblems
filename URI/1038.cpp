#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double vec[5];
    vec[0] = 4.00;
    vec[1] = 4.50;
    vec[2] = 5.00;
    vec[3] = 2.00;
    vec[4] = 1.50;
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Total: R$ %.2lf\n", vec[a-1]*b);
    return 0;
}
