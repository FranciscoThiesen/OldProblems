#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const long long mod = 1000000007;
 
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
 
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> digitCount(10, 0);
	unordered_map<int, long long> two_digits;
	unsigned long long ans = 0;
	string s;
	cin >> s;
	int sz = s.size();
    vector<int> zeros(sz, 0);
    if(s[0] == '0')
        zeros[0]++;
	for(int i = sz; i >= 0; --i)
	{
		int dig = s[i] - '0';
		if(dig == 8)
		{
			ans++;
			ans %= mod;
		}
        if(dig == 0)
        {
            ans++;
            ans %= mod;
        }
		for(auto& p : two_digits)
		{
			int cand = (dig*100 + p.first);
			if(cand%8 == 0)
			{
                ans += power(2, i, mod) * (p.second % mod);
            }
            ans %= mod;
		} 
		for(int i = 0; i < 10; ++i)
		{
			if(digitCount[i] != 0)
			{
				int dup = 10*dig + i;
                if(two_digits.find(dup) == two_digits.end())
                {
                    two_digits.insert(make_pair(dup, digitCount[i]));    
                }
				else
                    two_digits[dup] += digitCount[i];
                if(dup%8 == 0)
                {
                    ans+= digitCount[i];
                    ans %= mod;
                }
			}
		}
		digitCount[dig]++;
	}
	cout << ans % mod<< endl;
	return 0;
}