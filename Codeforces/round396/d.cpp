/*input
3 3 4
hate love like
1 love like
2 love hate
1 hate like
love like
love hate
like hate
hate like
*/

#include <bits/stdc++.h>

using namespace std;

#define gcd                         __gcd
#define OR |
#define AND &
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
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

struct UnionFind {
    int nsize;
    vi parent, size;

    UnionFind(int n) : nsize(n) {
        size.resize(n, 1);
        parent.resize(n);
        iota(ALL(parent), 0);
    }

    int unions(int u, int v) {
        if (find(u) == find(v))
            return 0;
        size[parent[v]] += size[parent[u]];
        parent[parent[u]] = parent[v];
        nsize--;
        return 1;
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
};

int main()
{
	IOS
	int n, m, q;
	cin >> n >> m >> q;
	int alfa = 100000;
	vector<vector<int> > syn(2*n + 2);
	vector<vector<int> > ant(2*n + 2);
	vector<vector<int> > graph(2*n + 2);
	vector<vector<int> > graphRev(2*n + 2);


	UnionFind uf(2*alfa + 2);

	unordered_map<int, int> cc;
	map<string, int> idx;
	unordered_map<int, unordered_set<int> > implication;
	int glob = 0;
	string s;
	for(int i = 0; i < n; ++i)
	{	
		cin >> s;
		idx[s] = glob;
		glob++;
	}
	F(i,0,m)
	{
		int x; string sa, sb;
		cin >> x >> sa >> sb;
		int a = idx[sa];
		int b = idx[sb];
		if(x == 1)
		{
			if(uf.find(a) == uf.find(alfa + b) || uf.find(b) == uf.find(alfa + a))
			{
				cout << "NO" << endl;
				continue;
			}	
			else
			{
				cout << "YES" << endl;
				uf.unions(alfa+a, alfa+b);
				uf.unions(a, b);
			}
		}
		else if(x == 2)
		{
			if(uf.find(a) == uf.find(b) || uf.find(b) == uf.find(a))
			{	
				cout << "NO" << endl;
				continue;
			}
			else
			{
				cout << "YES" << endl;
				uf.unions(a, alfa+b);
				uf.unions(b, alfa+a);
			}
		}
	}
	F(i,0,q)
	{
		string sa, sb;
		cin >> sa >> sb;
		int a = idx[sa];
		int b = idx[sb];
		if(uf.find(a) == uf.find(b))
			cout << 1 << endl;
		else if(uf.find(a) == uf.find(alfa+b))
		{
			cout << 2 << endl;
		}
		else
			cout << 3 << endl;
	}
	return 0;
}