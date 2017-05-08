/*input
8 6
1 3 20
4 2 1
6 5 5
10 1 1
15 3 6
21 8 8
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
#include <queue>
#include <functional>

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
	IOS
	int n, q;
	cin >> n >> q;
	vii idTempo(n+1);
	for(int i = 0; i <= n; ++i)
	{
		idTempo[i] = mp(i, 0);
	}
	for(int i = 0; i < q; ++i)
	{
		int ti, k, time;
		cin >> ti >> k >> time;
		vector<int> available;
		for(int j = 1; j <= n; ++j)
		{
			if(idTempo[j].se <= ti)
				available.pb(j);
		}
		int sum = 0;
		if(available.size() >= k)
		{
			for(int j = 0; j < k; ++j)
			{
				sum += available[j];
				idTempo[available[j]].se = ti + time;
			}
			cout << sum << endl;
		}
		else
			cout << -1 << endl;
	}
	return 0;
}