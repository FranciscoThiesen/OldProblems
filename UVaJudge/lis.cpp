#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).second()
#define pb push_back
#define mp make_pair
#define fr(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define fu(i, n) fr(i,0,n)

int main()
{
	register int t;
	cin >> t;
	while(t--)
	{
		int n;
		vector<int> vec;
		while(cin >> n)
		{
			vec.pb(n);
		}
		vector<int> solve((int) vec.size());
		solve[0] = 1;
		fr(i, 1, n)
		{
			solve[i] = 1;
			for(j, 0, i-1)
				if(vec[i] > vec[j])
					solve[i] = max(solve[j] + 1, solve[i]);
		}
		int mx = -1;
		int mxidx = -1;
		rp(i, n)
		{
			if(solve[i] > mx)
			{
				mx = solve[i];
				mxidx = i;
			}
		}
	}
}