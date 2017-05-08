#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ins insert
typedef pair<int, int> ii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	map<ii, set<ii> > magic;
	for(int i = 0; i < n; ++i)
	{
		int w,x,y,z;
		cin >> w >> x >> y >> z;
		magic[mp(w,x)].insert(mp(y,z));
	}


	int tot = 0;
	vector<tuple<int, int, int, int, int, int, int> > print;
	for(int i = 0; i < k; ++i)
	{
		int a,b,c,d,e;
		// user_id, cat_id, adv_id, show_time, click_flag
		cin >> a >> b >> c >> d >> e;
		ii tmp = mp(a,b);
		auto it = magic[tmp].lower_bound(mp(d,-1));
		if(it == magic[tmp].begin())
			continue;
		else
		{
			tot++;
			it--;
			print.pb(mt((*it).se,a,b, (*it).fi, c, d, e ));
		}
	}
	sort(print.begin(), print.end());
	cout << tot << endl;
	for(auto& p : print)
	{
		cout << get<1>(p) << " " << get<2>(p) << " " << get<3>(p) << " " << get<0>(p) << " " 
		<< get<4>(p) << " " << get<5>(p) << " " << get<6>(p) << endl;
	}
	return 0;
}