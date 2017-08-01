// https://www.codechef.com/FEB17/problems/GERMANDE

#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);
#define forn(i, v) for(int (i) = 0; (i) < (v); ++(i))
#define sz(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
 
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		vector<int> pref(a*b);
		for(int i = 0; i < a*b; ++i)
			cin >> pref[i];
		vector<ii> intervals;
		for (int x = 0; x < a*b; x += b)
		{
			intervals.pb(mp(x, x + b - 1));
		}
		int n = sz(intervals);
		vector<int> sums(n);
		fill(sums.begin(), sums.end(), 0);
		int winning = 0;
		bool win = false;
		for(int i = 0; i < n; ++i)
		{
			for (int s = intervals[i].fi; s <= intervals[i].se; ++s)
			{
				sums[i] += pref[s];
			}
		}
		for (auto& p : sums)
			if (p > b/2)
				winning++;
		if (winning > a/2)
		{
			win = true;
		}
		for(int i = 0; i < b; ++i)
			pref.pb(pref[i]);
 
		for (int j = 0; j < b - 1; ++j)
		{
			if (win)
				break;
			int w = 0;
			for (int i = 0; i < n; ++i)
			{
				int curSum = sums[i];
				intervals[i].first+=1;
				intervals[i].second+=1;
				curSum -= pref[intervals[i].first - 1];
				curSum += pref[intervals[i].se];
 				if(curSum > b/2)
					w++;
				sums[i] = curSum;
			}
			if (w > a/2)
				win = true;
		}
		if (win)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}  