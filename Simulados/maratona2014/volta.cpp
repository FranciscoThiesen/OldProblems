#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    double dif = b - a;
    printf("%.0f\n", ceil(b/dif));
    return 0;
}
