// RSA
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iterator>
#include <string>

using namespace std;

#define gcd __gcd
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define ull unsigned long long 

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<double> vd;


pair<ull, pair<ull, ull> > extendedEuclid(ull a, ull b) {
    ull x = 1, y = 0;
    ull xLast = 0, yLast = 1;
    ull q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
ull modInverse(ull a, ull m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

ull pow(ull a, ull b, ull MOD) {
ull x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}



ull power(ull x, ull y)
{
    ull temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if(y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
ull phi(ull n)
{
    ull result = n;
    for(ull i = 2; i*i < n; ++i)
    {
        if(n%i == 0)
        {
            while(n%i == 0)
                n/= i;
            result -= result/i;
        }
    }
    if(n > 1)
        result -= result/n;
    return result;
}

int main()
{
    ull n, e, c;
    cin >> n >> e >> c;
    ull d = 1;
    ull phiN = phi(n);
    d = modInverse(e, phiN);
    cout << pow(c,d,n)<< endl;
    return 0;
}
    
