#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int total = min(a,b);
    float rem = floor(max(a-total, b-total)/2.0); 
    printf("%d %.0f", total, rem);
    return 0;
}
