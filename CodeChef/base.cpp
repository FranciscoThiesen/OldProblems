#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define ll long long

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
        	result = result*value;
        value = value*value;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll ans = 1;
		if(n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		else if(n == 1 || n == 2)
		{
			cout << 1 << endl;
			continue;
		}
		else
		{
			for(ll i =  3; i <= floor(n/2); ++i)
			{
				if(i*i == n)
					ans++;
				else
				{
					ll bigDigit = (ll)floor(log2(n)/log2(i));
					if(n/fast_pow(i,bigDigit) <= 1)
						ans++;
				}
			}
			ans += n - (floor(n/2)+1) + 1;
		}
		cout << ans << endl;
	}
	return 0;
}