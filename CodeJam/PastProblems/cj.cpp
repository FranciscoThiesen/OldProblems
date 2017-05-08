#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <utility>
#include <limits>
#include <iomanip>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;

int main()
{
	int t;
	cin >> t;
	int n, d;
	for(int T = 1; T <= t; ++T)
	{
		cin >> n >> d;
		ll a, b;
		vector<pair<ll, ll> > pos_speed(d);
		for(int i = 0; i < d; ++i)
		{
			cin >> a >> b;
			pos_speed[i] = mp(a,b);
		}
		pos_speed.pb(mp(0ll, numeric_limits<ll>::max()));

		sort(pos_speed.rbegin(), pos_speed.rend());

		vector<double> arrival_time(d+1);
		arrival_time[0] = (double)(n - pos_speed[0].fi)/((double)pos_speed[0].se);
		double tmp;
		
		for(int i = 1; i <= d; ++i)
		{
			tmp = (double)(n - pos_speed[i].fi)/((double)pos_speed[i].se);
			arrival_time[i] = max(arrival_time[i-1], tmp);
		}
		printf("Case #%d: %.7lf\n", T, (double)n / arrival_time[d]);
	}
	return 0;
}
