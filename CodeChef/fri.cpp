#include <bits/stdc++.h>
using namespace std;
#define gcd                         __gcd
#define OR |
#define AND &
#define endl '\n'
#define XOR ^
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
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
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
// for debug
inline void pisz(int n) { printf("%d\n",n); }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 1001
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

int lca[MAXN][MAXN] = {{0}};

int main()
{
	// vamos comecar resolvendo o o caso que vale 40 pts
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	vector<vector<ii> > adjList;
	vector<int> rand;
	vector<int> dist;
	while(t--)
	{
		int n, p;
		cin >> n >> p;
		F(i,0,n)
		{
			int x, y, z;
			cin >> x >> y >> z;
			adjList[x-1].pb(mp(z, y-1));
			adjList[y-1].pb(mp(z, x-1));
		}
		F(j,0,p)
		{
			int k;
			cin >> k;
			rand.pb(k-1);
		}
		int root = rand[0];
		dist.resize(n);
		fill(dist.begin(), dist.end(), INF);
		dist[root] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > q;
		q.push(mp(0, root));
		while(!q.empty())
		{
			ii front = q.top();
			q.pop();
			int d = front.fi;
			int u = front.se;
			if(d > dist[u])
				continue;
			F(j,0,(int)adjList[u].size())
			{
				ii v = adjList[u][j];
				if(dist[u] + v.fi < dist[v.se])
				{
					dist[v.se] = dist[u] + v.fi;
					q.push(mp(dist[v.se], v.se));
				}
			}
		}
		
	}
}
