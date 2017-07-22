/*input
1
3
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
	vector<pair<short, short> > dirs;
	bool mat[400][400] = {{0}};
	dirs.pb(mp(1,0));//0
	dirs.pb(mp(1,1));//1
	dirs.pb(mp(1,-1));//2
	dirs.pb(mp(0,1));//3
	dirs.pb(mp(0,-1));//4
	dirs.pb(mp(-1,1));//5
	dirs.pb(mp(-1,-1));//6
	dirs.pb(mp(-1,0));//7
	queue< tuple<short, short, short, short, short> > rec;
	vector<short> recLevel(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> recLevel[i];
	}
	short x = 200; short y = 200;
	// posx, posy, recLevel, dir, paint
	rec.push(make_tuple(x, y, n, 3, recLevel[0]));
	while(!rec.empty())
	{
		auto f = rec.front();
		rec.pop();
		for(int i = 0; i < get<4>(f); ++i)
		{
			get<0>(f) += dirs[get<3>(f)].fi;
			get<1>(f) += dirs[get<3>(f)].se;
			mat[get<0>(f)][get<1>(f)] = 1;
		}
		if(get<2>(f) > 1)
		{
			if(get<3>(f) == 0)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 1, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 2, recLevel[n - get<2>(f) +1]));
			}
			if(get<3>(f) == 1)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 0, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 3, recLevel[n - get<2>(f) +1]));
			}
			if(get<3>(f) == 2)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 0, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 4, recLevel[n - get<2>(f) +1]));
			}
			if(get<3>(f) == 3)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 1, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 5, recLevel[n - get<2>(f) +1]));
			}
			if(get<3>(f) == 4)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 2, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 6, recLevel[n - get<2>(f) +1]));
			}
			if(get<3>(f) == 5)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 3, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 7, recLevel[n - get<2>(f) +1]));
			}
			if(get<3>(f) == 6)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 4, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 7, recLevel[n - get<2>(f) +1]));
			}
			if(get<3>(f) == 7)
			{
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 5, recLevel[n - get<2>(f) +1]));
				rec.push(make_tuple(get<0>(f), get<1>(f), get<2>(f) - 1, 6, recLevel[n - get<2>(f) +1]));
			}
		}
	}
	int ans = 0;
	for(int x = 0; x < 300; ++x)
	{
		for(int y = 0; y < 300; ++y)
		{
			if(mat[x][y])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}