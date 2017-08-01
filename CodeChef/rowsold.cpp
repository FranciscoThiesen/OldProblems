// https://www.codechef.com/APRIL17/problems/ROWSOLD
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define fu(i, n) fr(i,0,n)
 
typedef long long ll;
typedef pair<ll, ll> ii;
 
long long solve(string& s)
{
	vector<ii> comp;
	char num = s[0];
	ll curSz = 1;
	fr(i, 1, s.size())
	{
		if(s[i] == num)curSz++;
		else{
			comp.pb(mp(curSz,(ll) num - '0'));
			curSz = 1;
			num = s[i];
		}
	}
	comp.pb(mp(curSz, (ll)num - '0'));
	long long  resp = 0;
	fu(i, comp.size()-1)
	{
		if(comp[i].se == 0) continue;
		resp += comp[i].fi * comp[i+1].fi + comp[i].fi;
		if(i + 2 < comp.size())
		{
			comp[i+2].fi += comp[i].fi;
		}
	}
 
	return resp;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
} 