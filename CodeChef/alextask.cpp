// https://www.codechef.com/NOV16/problems/ALEXTASK
#include <bits/stdc++.h>
#include <limits>
 
 
#define gcd __gcd
#define endl '\n'
 
using namespace std;
 
unsigned long long lcm(unsigned long long a, unsigned long long b)
{
	return (a*b)/(gcd(a,b));
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	vector<int> nums(500);
	while(t--)
	{
		int n;
		cin >> n;
		unsigned long long ans = numeric_limits<unsigned long long>::max();
		for(int i = 0; i < n; ++i)
		{
			unsigned long long k;
			cin >> k;
			nums[i] = k;
		}	
		for(int i = 0; i < n+1; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				ans = min(ans, lcm(nums[i], nums[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
} 