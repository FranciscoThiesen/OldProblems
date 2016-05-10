#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned long long int x)
{
    if(x == 1)
        return false;
    for(unsigned long long i = 2; i <= ceil(sqrt(x)); ++i)
        if(x%i == 0)
            return false;
    return true;
}

int main()
{
    long long a;
    cin >> a;
    if(a < 0)
        a = 0 - a;
    if(isPrime(a))
        printf("sim\n");
    else
        printf("nao\n");
    return 0;
}
