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
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) 
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

vector<int> visited(200000, 0);
set<int> rep;
unordered_set<int> jaSaiu;
void dfs(vector<vector<int> > adjList, int root, int daVez)
{
	for(auto& p : adjList[daVez])
	{
		if(root == p)
		{
			rep.insert(p);
			return;
		}
		else if(jaSaiu.find(p) != jaSaiu.end())
		{
			visited[p] = 1;
			rep.insert(p);
			return;
		}
		else
		{
			jaSaiu.insert(p);
			dfs(adjList, root, p);
		}
	}
}

int main()
{
	int t;
	getI(t);
	while(t--)
	{
		rep.clear();
		int n;
		getI(n);
		int ans = 0;
		vector<int> arr(n);
		vvi adjList(n+1);
		visited.resize(n);
		fill(visited.begin(), visited.end(), 0);
		F(i,0,n)
		{
			int x;
			getI(x);
			arr[i] = x;
			int adjacente = i + x + 1;
			adjList[i].pb(adjacente%n);
		}
		F(i,0,n)
		{
			if(visited[i] == 0)
			{
				jaSaiu.clear();
				jaSaiu.insert(i);
				dfs(adjList, i, i);
				visited[i] = 1;
			}
		}
		cout << rep.size() << endl;
	}
	return 0;
}
