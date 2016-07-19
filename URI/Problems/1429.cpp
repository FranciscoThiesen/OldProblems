#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cmath>

using namespace std;
int fac(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return fac(n-1)*n;
}
int main()
{
    string num;
    while(true)
    {
        long long ans = 0;
        cin >> num;
        for(int i = 0; i < num.size(); ++i)
        {
            if(i == 0 && num[i] == '0')
                return 0;
            int a = num[i] - '0';
            a *= fac((int)num.size()-i);
            ans += a;
        }
        cout << ans << endl;
    }
    return 0;
}
