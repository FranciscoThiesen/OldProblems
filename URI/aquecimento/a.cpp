#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int r = a + b + c;
    int ans = r;
    if(r < 0)
        ans = 24 + r;
    else if(r >= 24)
        ans = ans - 24;
    else
        ans = ans%24;

    cout << ans << endl;
}
