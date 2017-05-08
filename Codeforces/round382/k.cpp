#include <bits/stdc++.h>

using namespace std;

#define gcd __gcd

int vec[100001] = {0};
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		int ans = 1;
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			vec[i] = x;
		}

		vector<int> dp(n, 0);
		dp[n-1] = 1;
		for(int j = n-2; j >= 0; --j)
		{
			int mx = 0;
			for(int v = j + 1; v < n; ++v)
			{
				if(dp[v] > mx && gcd(vec[j], vec[v]) > 1)
					mx = dp[v];
			}
			dp[j] = mx + 1;
			if(mx + 1 > ans)
				ans = mx + 1;
		}
		cout << ans << endl;
		memset(vec, 0, sizeof vec);
	}
	return 0;
}
