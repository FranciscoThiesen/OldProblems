#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> digitCount(10, 0);
	unordered_set<int> two_digits;
	unordered_set<int> three_digs;
	unsigned long long ans = 0;
	string s;
	cin >> s;
	int sz = s.size();
	for(int i = sz; i >= 0; --i)
	{
		int dig = s[i] - '0';
		if(dig == 8 && digitCount[8] == 0)
		{
			ans++;
			ans %= mod;
		}
		for(auto& p : two_digits)
		{
			int cand = (dig*100 + p);
			if((dig*100 + p)%8 == 0)
			{
				if(three_digs.find(cand) == three_digs.end())
				{
					ans += (i+1);
					three_digs.insert(cand);
				}
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
					two_digits.insert(dup);
					if(dup%8 == 0)
					{
						ans++;
						ans %= mod;

					}
				}
			}
		}
		digitCount[dig]++;
	}
	cout << ans % mod<< endl;
	return 0;
}