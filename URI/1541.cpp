#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    double a = 1, b = 1, c = 1;
    while(a != 0)
    {
        cin >> a;
        if(a == 0)
            break;
        cin >> b >> c;
        double ans = (a*b)*((int)100/c);
        int af = (int)sqrt(ans);
        cout << af << endl;
    }
    return 0;
}
