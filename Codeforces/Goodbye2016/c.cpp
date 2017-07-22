/*input
*/
#include <bits/stdc++.h>
using namespace std;
#define gcd                         __gcd
#define lcm(a, b) ((a*b)/gcd(a,b))
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1001001001
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

int main()
{
	int n;
	cin >> n;
	int curDiv;
	bool up;
	vector<ii> changes;
	int ans = 0;
	F(i,0,n)
	{
		int x, y;
		cin >> x >> y;
		changes.pb(mp(x,y));
	}
	vi maxPossible(n);
	int maxPrev;
	bool pos = true;
	F(i,0,n)
	{
		if(i == 0)
		{
			if(changes[i].se == 1)
			{
				maxPrev = INF;
				maxPossible[0] = INF;
			}
			else
			{
				maxPrev = 1899 + changes[i].fi;
				maxPossible[0] = maxPrev;
			}

		}
		else
		{
			if(changes[i].se == 1)
			{
				if(maxPrev < 1900)
				{
					pos = false;
					break;
				}
				if(maxPrev == INF)
				{
					maxPossible[i] = INF;
				}
				else
				{
					maxPossible[i] = maxPrev + changes[i].fi;
					maxPrev = maxPossible[i];
				}
			}
			else
			{
				maxPossible[i] = min(1899 + changes[i].first, maxPrev + changes[i].first);
				maxPrev = maxPossible[i];
			}
		}
	}
	for(int i = 1; i < n; ++i)
	{
		if(changes[i-1].se == 1 && changes[i].se == 2 && changes[i-1].fi >= 0)
		{
			pos = false;
			break;
		}
		if(changes[i-1].se == 2 && changes[i].se == 1 && changes[i-1].fi <= 0)
		{
			pos = false;
			break;
		}

	}
	if(!pos)
		cout << "Impossible" << endl;
	else
	{
		if(maxPossible[n-1] == INF)
			cout << "Infinity" << endl;
		else
			cout << maxPossible[n-1] << endl;
	}
	return 0;
}