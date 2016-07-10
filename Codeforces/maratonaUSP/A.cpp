#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

bool isPrime(int x)
{
    if(x == 1)
        return false;
    if(x == 2)
        return true;
    for(int i = 2; i < ceil(sqrt(x)); ++i)
    {
        if(x%i == 0)
            return false;
    }
    return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(isPrime(gcd(a,b)) == true)
            printf("Sim\n");
        else
            printf("Nao\n");
    }
    return 0;
}
