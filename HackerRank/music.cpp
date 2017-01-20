#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int main()
{
	int n;
	vector<pair<int, int> > intervals;
	intervals.pb(mp(numeric_limits(int)::min(), numeric_limits(int)::max()));
 	sz = 1;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		intervals.pb(mp(x, intervals[sz-1].se));
		intervals[sz-1] = mp(intervals[sz-1].fi, x);
		sz++;
	}
	int m, h1, h2;
	cin >> m >> h1 >> h2;
	
}