#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair

vector<pair<int, int> > coord;

int main()
{
	int t;
	int test = 1;
	scanf("%d", &t);
	while(t--)
	{
		int a,b;
		int numQuery;
		scanf("%d %d", &a, &b);
		coord.clear();
		int x = 0;
		int y = 0;
		int side = 0;
		int lst = 1;
		int it= 1;
		vector<pair<int, int> > dir;
		dir.pb(mp(-1,0));
		dir.pb(mp(0,1));
		dir.pb(mp(1,0));
		dir.pb(mp(0,-1));
		for(int i = 0; i < 70000; ++i)
		{
			if(a*x + b != y)
			{
				coord.pb(mp(x,y));
				//cout << i << "x " << x << "  y " << y << endl;
			}
			if(it > 0)
			{
				it--;
				x += dir[side%4].fi;
				y += dir[side%4].se;
			}
			if(it==0)
			{
				if(side%4 == 1 || side%4 == 3)
				{
					lst++;
				}
				it = lst;
				side++;
			}
		}
		scanf("%d", &numQuery);
		cout << "Caso " << test << endl;
		test++;
		for(int j = 0; j < numQuery; ++j)
		{
			int f,g;
			scanf("%d %d", &f, &g);
			// TRACE(cout << f << " " <<g << endl;
			// 	cout MM
			// 	);
			if(a*coord[f].fi + b > coord[f].se && a*coord[g].fi + b > coord[g].se)
				printf("Mesmo lado da fronteira\n");
			else if(a*coord[f].fi + b < coord[f].se && a*coord[g].fi + b < coord[g].se)
				printf("Mesmo lado da fronteira\n");
			else
				printf("Lados opostos da fronteira\n");
		}

	}
	return 0;
}