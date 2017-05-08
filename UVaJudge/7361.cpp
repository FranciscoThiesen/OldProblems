#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iostream>

#define ll unsigned long long
#define INF 1000000000

using namespace std;

void multiply(ll F[2][2], ll M[2][2])
{
    ll x = (F[0][0]*M[0][0])%INF + (F[0][1]*M[1][0])%INF;
    ll y =  (F[0][0]*M[0][1])%INF + (F[0][1]*M[1][1])%INF;
    ll z =  (F[1][0]*M[0][0])%INF + (F[1][1]*M[1][0])%INF;
    ll w =  (F[1][0]*M[0][1])%INF + (F[1][1]*M[1][1])%INF;
 
    F[0][0] = x%INF;
    F[0][1] = y%INF;
    F[1][0] = z%INF;
    F[1][1] = w%INF;
}

 
int power(ll F[2][2], ll n)
{
    if(n == 0 || n == 1)
        return 0;
    power(F,n/2);
    multiply(F,F);
    ll M[2][2] = {{1,1}, {1,0}};
    if(n%2 != 0)
        multiply(F,M);
    return 0;
}
 
/* function that returns nth Fibonacci number */
ll fib(ll n)
{
    ll F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}
 
/* Optimized version of power() in method 4 */
 
/* Driver program to test above function */
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll k, n;
        cin >> k >> n;
        cout << k << " " << fib(n) << endl;
    }
    return 0;
}
