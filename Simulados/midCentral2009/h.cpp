#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main(void)
{
	int t = 1;
	while(t != 0)
	{
		
		cin >> t;
		if(!t)
			break;

		int r;
		cin >> r;

		vector<pair<pair<int, int>, int> > towers;

		for(int i = 0; i < t; i++)
		{
			int a, b, c;

			cin >> a >> b >> c;

			towers.pb(mp(mp(a, b), c));
		}

		vector<pair<int, int> > seg;
		vector<pair<int, int> > segFinal;

		for(int i = 0; i <= r; i++)
		{
			int a, b;
			cin >> a >> b;

			seg.pb(mp(a, b));
		}

		for(int i = 0; i < seg.size() - 1; i ++)
		{
			segFinal.pb(seg[i]);

			if(seg[i].fi == seg[i + 1].fi)
			{
				if(seg[i].se > seg[i + 1].se)
				{
					for(int j = seg[i].se - 1; j > seg[i + 1].se; j--)
					{
						segFinal.pb(mp(seg[i].fi, j));
					}
				}
				else
				{
					for(int j = seg[i].se + 1; j < seg[i + 1].se; j++)
					{
						segFinal.pb(mp(seg[i].fi, j));
					}
				}
			}
			else if(seg[i].se == seg[i + 1].se)
			{
				if(seg[i].fi > seg[i + 1].fi)
				{
					for(int j = seg[i].fi - 1; j > seg[i + 1].fi; j--)
					{
						segFinal.pb(mp(j, seg[i].se));
					}
				}
				else
				{
					for(int j = seg[i].fi + 1; j < seg[i + 1].fi; j++)
					{
						segFinal.pb(mp(j, seg[i].se));
					}
				}
			}
			else if(abs(seg[i].se - seg[i].fi) == abs(seg[i + 1].se - seg[i + 1].fi))
			{
				if(seg[i].fi > seg[i + 1].fi)
				{
					int k = seg[i].se - 1;
					for(int j = seg[i].fi - 1; j > seg[i + 1].fi; j--)
					{
						segFinal.pb(mp(j, k));
						k--;
					}
				}
				else
				{
					int k = seg[i].se + 1;
					for(int j = seg[i].fi + 1; j < seg[i + 1].fi; j++)
					{
						segFinal.pb(mp(j, k));
						k++;
					}
				}
			}
			else
			{
				if(seg[i].fi > seg[i + 1].fi)
				{
					int k = seg[i].se + 1;
					for(int j = seg[i].fi - 1; j > seg[i + 1].fi; j--)
					{
						segFinal.pb(mp(j, k));
						k++;
					}
				}
				else
				{
					int k = seg[i].se - 1;
					for(int j = seg[i].fi + 1; j < seg[i + 1].fi; j++)
					{
						segFinal.pb(mp(j, k));
						k--;
					}
				}
			}
		}

		

		for(int i = 0; i < segFinal.size(); i++)
		{
			cout << segFinal[i].fi << " " << segFinal[i].se << endl;
		}


	}

	return 0;
}