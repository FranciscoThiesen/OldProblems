#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define pb push_back
using namespace std;

vector<int> primes;
bool checkPrime(int n)
{
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    for(int i = 2; i < ceil(sqrt(n)); ++i)
        if(n%i == 0)
            return false;
    return true;
}
int main()
{
    for(int k = 2; k < 31662;k++)
        if(checkPrime(k))
            primes.pb(k);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool chefWin = false;
        if(checkPrime(n) == true || n == 1)
            chefWin = true;
        else
        {
            for(int p = 0; p < primes.size(); ++p)
            {
                int cur = 0;
                if(n%primes[p] == 0)
                    cur = primes[p];
                else
                    continue;
                while(cur < n)
                {
                    cur *= primes[p];
                }
                if(cur == n)
                {
                    chefWin = true;
                    break;
                }
            }
        }

        if(chefWin == true)
            cout << "Chef" << endl;
        else
            cout << "Misha" << endl;

    }

    return 0;
}
