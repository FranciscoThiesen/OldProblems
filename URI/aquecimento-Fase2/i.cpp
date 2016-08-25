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
typedef vector<ii> vii;
set<int> componente;
int totalSize = 0;
// componentes conexos
void dfs(int root, vector<vii>& AdjList, vector<int>& visited)
{
	std::ios::sync_with_stdio(false);
	componente.insert(root);
	F(i,0,AdjList[root].size())
	{
		cout << root << " " << AdjList[root][i].first << endl;
		if(visited[AdjList[root][i].first] == 0)
		{
			cout << root << " " << AdjList[root][i].first << endl;
			if(root < AdjList[root][i].fi)
				totalSize += AdjList[root][i].second;
			componente.insert(AdjList[root][i].first);
			dfs(AdjList[root][i].first, AdjList, visited);
			cout << root << " " << AdjList[root][i].first << endl;
		}
	}	
}

/*int bfs(int root, vector<vii>& AdjList, vector<int>& visited)
{
	queue<int> q;
	q.push(root);
	visited[root] = 1;
	while(q.empty())
	{
		int u = q.front();
		q.pop();
		F(i,0,AdjList[u].size())
		{
			int v = AdjList[u][i];
			if(
} */


int main()
{
	int n, m;
	getII(n,m);
	vector<int> buracos(n+1, 0);
	vector<vii> AdjList(n+1);
	vector<int> visited(n+1, 0);
	F(i,0,m)
	{
		int a, b, c;
		getIII(a,b, c);
		AdjList[a].pb(mp(b,c));
		AdjList[b].pb(mp(a,c));
	}
	cout << "vrau" << endl;
	int minx = INF;
	int ans = 0;
	F(i,1,n+1)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			dfs(i, AdjList, visited);
			for(auto& p : componente)
				cout << p << endl;
			cout << "miau" << endl;

		
			if(totalSize/(int)(componente.size()) < minx)
			{
				auto it = componente.end();
				ans = *it;
				minx = totalSize/(int)(componente.size());
			}
			else if(totalSize/(int)(componente.size()) == minx)
			{
				ans = max(ans, *(componente.end()));
			}
			componente.clear();
			totalSize = 0;
		
		}
	}
	cout << ans << endl;
	return 0;
	
}