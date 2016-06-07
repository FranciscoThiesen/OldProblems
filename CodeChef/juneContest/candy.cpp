#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <bitset>
#define ull unsigned long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ull a, b, c, d;
        cin >> a >> b >> c >> d;
        ull ans;
        if(a > b)
        {
            ans = a-b;
            ull nb = (max(1.0,ceil((a-b)/d)))*d + b;// caso 1 dar balas D ate B passar A arredondando p cima
            ull nb2 = (max(1.0,floor((a-b)/d)))*d + b;// caso 1 dar balas D ate B passar A arredondando p cima
            ans = min(ans, nb-a);
            ans = min(ans, nb2-a);
            nb -= d;
            nb2 -= d;
            ans = min(ans, a-nb);// caso 2 dar balas D ate B passar A, e depois tirar uma bala D de B
            ans = min(ans, a-nb2);// caso 2 dar balas D ate B passar A, e depois tirar uma bala D de B
            
        }
        else if(b > a)
        {
            ans = b-a;
            ull fuck = 1;
            ull na = (max(1.0,ceil((b-a)/c)))*c + a;// caso 1 dar balas D ate B passar A arredondando p cima
            cout << na << endl;
            ull na2 = (max(1.0,floor((b-a)/c)))*c + a;// caso 1 dar balas D ate B passar A arredondando p cima
            cout << na2 << endl;
            ans = min(ans, na-b);
            ans = min(ans, na2-b);
            na -= c;
            na2 -= c;
            ans = min(ans, b-na2);// caso 2 dar balas D ate B passar A, e depois tirar uma bala D de B
            ans = min(ans, b-na2);// caso 2 dar balas D ate B passar A, e depois tirar uma bala D de B
            
        }
        cout << ans << endl;
    }
    return 0;
}
