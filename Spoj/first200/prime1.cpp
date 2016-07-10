#include <cstdio>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;

vector<bool> primes;

void crivo(int upperLimit, int lowerLimit)
{
    primes.assign(upperLimit+1, true);
    for(int p = 2; p*p < upperLimit; ++p)
    {
        if(primes[p] == true)
        {
            for(int num = p*2; num <= upperLimit; num+=p)
            {
                primes[num] = false;
            }
        }
    }
    for(int k = max(lowerLimit, 2); k <= upperLimit; ++k)
    {
        if(primes[k])
            printf("%d\n", k);
    }
    primes.clear();
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int a, b;
        cin >> a >> b;
        crivo(b,a);
        cout << endl;
    }
    return 0;
}
