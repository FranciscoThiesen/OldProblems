#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    unsigned long long int n, a, b, c;
    cin >> n >> a >> b >> c;
    unsigned long long int total = 0;
    while(n >= min(a,b))
    {
        if(a <= b - c)
        {
            if(n >= a)
            {
                total += n/a;
                n -= (n/a)*a;
            }
        }
        else
        {
            if(n >= b)
            {
                total += (n-c)/(b-c);
                if(n - ((n-c)/(b-c)) >= a)
                {
                    total +=  (n - ((n-c)/(b-c)))/a;
                    break;
                }
                else
                    break;
            }
        }
    }
    cout << total << endl;
    return 0;

}
