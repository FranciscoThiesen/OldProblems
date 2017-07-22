/*input
7 2 2 5
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, g, b;
	cin >> n >> k >> g >> b;
	if(g == b)
	{
		for(int i = 0; i < g; ++i)
			cout << "GB";
		cout << endl;
	}
	else if(g > b)
	{
		// 0 for green, 1 for black
		vii tea;
		tea.pb(mp(0, 1));
		for(int i = 0; i < b; ++i)
		{
			tea.pb(mp(1,1));
			tea.pb(mp(0,1));
		}
		g -= (b + 1);
		for(int i = 0; i < tea.size(); ++i)
		{
			if(tea[i].first == 0)
			{
				int add = k - tea[i].second;
				add = min(g, add);
				tea[i].second += add;
				g -= add;
			}
			if(g == 0)
				break;
		}
		if(g > 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		string ans;
		for(int i = 0; i < tea.size(); ++i)
		{
			for(int j = 0; j < tea[i].second; ++j)
			{
				if(tea[i].first%2 == 0)
					ans += 'G';
				else
					ans += 'B';
			}
		}
		cout << ans << endl;
	}
	else if(b > g)
	{
		// 0 for green, 1 for black
		vii tea;
		tea.pb(mp(1, 1));
		for(int i = 0; i < g; ++i)
		{
			tea.pb(mp(0,1));
			tea.pb(mp(1,1));
		}
		b -= (g + 1);
		for(int i = 0; i < tea.size(); ++i)
		{
			if(tea[i].first == 1)
			{
				int add = k - tea[i].second;
				add = min(b, add);
				tea[i].second += add;
				b -= add;
			}
			if(b == 0)
				break;
		}
		if(b > 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		string ans;
		for(int i = 0; i < tea.size(); ++i)
		{
			for(int j = 0; j < tea[i].second; ++j)
			{
				if(tea[i].first%2 == 0)
					ans += 'G';
				else
					ans += 'B';
			}
		}
		cout << ans << endl;
	}
	return 0;
}