#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }

int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    return 0;
}
