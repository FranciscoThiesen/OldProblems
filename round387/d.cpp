/*input
10 6
2 -5 1 3 0 0 -4 -3 1 0
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;


#define gcd __gcd
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> days(n);
	int winDays = 0;
	vii q;
	int sz = 0;
	bool neg = false;
	for(int i = 0; i < n; ++i)
	{
		cin >> days[i];
		if(days[i] < 0)
		{
			winDays++;
			if(neg)
			{
				sz++;
			}
			else
			{
				neg = true;
				if(sz > 0)
				{
					q.pb(mp(sz, 1));
				}
				sz = 1;
			}
		}
		if(days[i] >= 0)
		{
			if(!neg)
			{
				sz++;
			}
			else
			{
				neg = false;
				if(sz > 0)
				{
					q.pb(mp(sz, -1));
				}
				sz = 1;
			}
		}
	}
	int free = k - winDays;
	if(neg)
		q.pb(mp(sz, -1));
	else
		q.pb(mp(sz, 1));
	int ans = 0;
	bool winter = false;
	if(free < 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < q.size(); ++i)
	{
		if(q[i].se == -1 && winter == false)
		{
			ans++;
			winter = true;
		}
		else if(q[i].se == 1 && winter == true)
		{
			if(free >= q[i].fi)
			{
				free -= q[i].fi;
			}
			else
			{
				winter = false;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}