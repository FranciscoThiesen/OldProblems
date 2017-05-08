#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cmath>
#include <functional>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ull, ull> pll;

/* Algorithm ideia

For any given adjacent pairs of sides, insert the range of the possible third size.. 
After that, we shall count the number of numbers that are available..
Maybe it is necessary to use some fancy data structure like segment tree or something similar, to handle the invervals
Problem B of the February Codechef Contest

*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ull l, r;
	cin >> l >> r;
	set<pll> intervals;
	intervals.insert(mp(l, r));
	vector<ull> sz(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> sz[i];
	}
}