// https://www.codechef.com/FEB17/problems/MAKETRI
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define F(i,j,k) for(int (i) = (j); (i) < (k); ++(i))
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ull, ull> pu;
 
vector<pu> mergeIntervals(vector<pu>& inter)
{
	sort(all(inter));
 
	stack<pu> s;
 
	s.push(inter[0]);
 
	F(i,1, inter.size())
	{
		pu top = s.top();
 
		if(top.se < inter[i].fi)
		{
			s.push(inter[i]);
		}
		else if(top.se < inter[i].se)
		{
			top.se = inter[i].se;
			s.pop();
			s.push(top);
		}
	}
 
	vector<pu> ret;
	while(!s.empty())
	{
		pu t = s.top();
		ret.pb(t);
		s.pop();
	}
	return ret;
}
 
int main()
{
	ull n, l, r;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r;
	vector<ull> sides(n);
	F(i,0,n)
		cin >> sides[i];
	vector<pu> intervals(n-1);
	sort(all(sides));
 
	//shall find the available interval for the third side
	F(i,0,n-1)
	{
		ull x1 = sides[i];
		ull x2 = sides[i+1];
		
		ull mn = sides[i+1] - sides[i] + 1;
		ull mx = sides[i+1] + sides[i] - 1;
 
		if(mx > 0)
		{
			mn = max((ull)0, mn);
			intervals[i] = mp(mn, mx);
		}
		
	}
	vector<pu> merged = mergeIntervals(intervals);
 
	ull ans = 0;
	for(auto& p : merged)
	{
		if(p.se < l || p.fi > r)
			continue;
		else
			ans += min(p.se, r) - max(p.fi, l) + 1;
	}
	cout << ans << endl;
	return 0;
 
} 