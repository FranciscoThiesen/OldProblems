#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <utility>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x)) 
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0; const int NULO = -1;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;}

vector<vector<pair<int, int> > > cubos;
vector<pair<int, int> > temp;
vector<pair<int, int> > temp2;
int main()
{
	int t = 1;
	while(t != 0)
	{
		cubos.clear();
		scanf("%d", &t);
		if(t == 0)
			break;
		int ans = 0;
		for(int i = 0; i < t; ++i)
		{
			temp.clear();
			temp2.clear();
			int a, b, c, d, e, f;
			cin >> a;
			cin >> b >> c >> d >> e;
			cin >> f;
			temp.pb(mp(min(a,f), max(a,f)));
			temp.pb(mp(min(b,d), max(b,d)));
			temp.pb(mp(min(c,e), max(c,e)));
			//sort(temp.begin(), temp.end());
			bool rep = false;
			for(int j = 0; j < cubos.size(); ++j)
			{
				if(temp[0].fi == cubos[j][0].fi && temp[0].se == cubos[j][0].se && temp[1].fi == cubos[j][1].fi && temp[1].se == cubos[j][1].se && temp[2].fi == cubos[j][2].fi && temp[2].se == cubos[j][2].se)
				{
					rep = true;
					break;
				}
				// f,a  d,b c,e
				else if(temp[0].fi == cubos[j][0].se && temp[0].se == cubos[j][0].fi && temp[1].fi == cubos[j][1].se && temp[1].se == cubos[j][1].fi && temp[2].fi == cubos[j][0].fi && temp[2].se == cubos[j][2].se)
				{
					rep = true;
					break;
				}
				//f,a b,d ,e,c
				else if(temp[0].fi == cubos[j][0].se && temp[0].se == cubos[j][0].fi && temp[1].fi == cubos[j][1].fi && temp[1].se == cubos[j][1].se && temp[2].fi == cubos[j][0].se && temp[2].se == cubos[j][2].fi)
				{
					rep = true;
					break;
				}
				//a,f d,b e,c
				else if(temp[0].fi == cubos[j][0].fi && temp[0].se == cubos[j][0].se && temp[1].fi == cubos[j][1].se && temp[1].se == cubos[j][1].fi && temp[2].fi == cubos[j][0].se && temp[2].se == cubos[j][2].fi)
				{
					rep = true;
					break;
				}
			}
			if(rep == false)
			{
				cubos.pb(temp);
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}