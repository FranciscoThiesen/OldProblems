#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
#define pllu pair<ull, ull>

#define MAXN 100010

ll pos[MAXN] = {0};
ll cost[MAXN] = {0};
ll dp[MAXN] = {0}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			ull x, c;
			cin >> x >> c;
			pos[i] = x;
			cost[i] = c;
		}
		
		dp[0] = max(0, cost[0] - (pos[1] - pos[0])*pos[0]);
		ll bestProfit; 
		if(dp[0] > 0)
			bestProfit = pos[0];
		else
			bestProfit = 0;
		ull totalProfit = dp[0];
		for(int i = 2; i < n; ++i)
		{
			dp[i] = max(bestProfit* ())
		}
	}

}