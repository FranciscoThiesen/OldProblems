/*input
0 0
1 0
0 1
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
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	set<pair<int, int> > pts;

	//starting by vertex one
	int dif1_2x = x1-x2;
	int dif1_2y = y1-y2;
	pts.insert(mp(x3 + dif1_2x, y3 + dif1_2y));
	pts.insert(mp(x3 - dif1_2x, y3 - dif1_2y));
	int dif1_3x = x1-x3;
	int dif1_3y = y1-y3;
	pts.insert(mp(x2 + dif1_3x, y2 + dif1_3y));
	pts.insert(mp(x2 - dif1_3x, y2 - dif1_3y));
	int dif2_3x = x2-x3;
	int dif2_3y = y2-y3;
	pts.insert(mp(x1 + dif2_3x, y1 + dif2_3y));
	pts.insert(mp(x1 - dif2_3x, y1 - dif2_3y));
	int tot = 0;
	for(auto& p : pts)
	{
		if(p.fi != x1 || p.se != y1)
		{
			if(p.fi != x2 || p.se != y2)
			{
				if(p.fi != x3 || p.se != y3)
				{
					tot++;
				}
			}
		}
	}
	cout << tot << endl;
	for(auto& p : pts)
	{
		if(p.fi != x1 || p.se != y1)
		{
			if(p.fi != x2 || p.se != y2)
			{
				if(p.fi != x3 || p.se != y3)
				{
					cout << p.fi << " " << p.se << endl;
				}
			}
		}
	}
	return 0;
}