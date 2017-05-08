/*input
6
2 4
0 5
4 2
2 1
1 1
4 2
*/
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

#define gcd                         __gcd
#define OR |
#define AND &
#define XOR ^
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define sc(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a)
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a,b,c) printf("%d %d %d\n", a, b, c)
#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow)while(testow--) //for multilple cases problems
#define whileZ int T; sc(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
#define sz(x) ((int)((x).size()))
#define remax(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define remin(a,b) (a)=min((a),(b));
#define snuke(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define CPRESENT(c,x) (find(all(c),x) != (c).end()) 
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
#define MAXN 1000001
#define LOGMAXN 20
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

unordered_map<int, vector<int> > adjMap;
unordered_map<int, vector<int> > revAdjMap;
vector<int> bt(MAXN, 0);
unordered_map<int, vector<int> > elems;
vector<int> sums(MAXN, 0);
vector<int> lvl(MAXN);
unordered_set<int> parents;
int root;
// void dfs(int u){
// 	for(auto& p : adjMap[u])
// 	{
// 		if(p != dad[u])
// 		{
// 			dad[p] = u;
// 			lvl[p] = lvl[u] + 1;
// 			dfs(p);
// 		}
// 	}
// }

// void pre(root) {
//     dad[root] = lvl[root] = 0;
//     dfs(root);
//     for (int i = 0; i < n; i++)
//         anc[i][0] = dad[i];
//     for (int j = 1; 1<<j < n; j++)
//         for (int i = 0; i < n; i++)
//             anc[i][j] = anc[anc[i][j-1]][j-1];
// }

// int lca(int u, int v) {
//     if (lvl[u] < lvl[v])
//         swap(u, v);
//     int log;
//     for (log = 1; (1<<log) <= lvl[u]; log++);
//     log--;
//     for (int i = log; i >= 0; i--)
//         if (lvl[u] - lvl[v] >= (1<<i))
//             u = anc[u][i];
//     if (u == v)
//         return u;
//     for (int i = log; i >= 0; i--)
//         if (anc[u][i] != anc[v][i])
//             u = anc[u][i], v = anc[v][i];
//     return dad[u];
// }

int recSum(int k)
{
	if(sums[k] != 0)
		return sums[k];
	sums[k] = bt[k];
	for(auto& p : adjMap[k])
	{
		
		sums[k] += recSum(p);
		lvl[p] = lvl[k] + 1;
	}
	return sums[k];
}

int comeBack(int node, int val)
{
	parents.insert(node);
	int now = node;
	int dad = revAdjMap[node][0];
	if(sums[dad] - sums[node] == val && dad != root)
	{
		return dad;
	}
	parents.insert(dad);
	while(now != root)
	{
		now = dad;
		if(now == root)
		{
			break;
		}
		dad = revAdjMap[now][0];
		parents.insert(dad);
		if(sums[dad] - sums[node] == val && dad != root)
		{
			return dad;
		}

	}
	return -1;
}
int main()
{
	int a;
	sc(a);
	int x, y;
	F(i,0,a)
	{
		sc2(x,y);
		if(!x) root = i;
		else
		{
			adjMap[x-1].pb(i);
			revAdjMap[i].pb(x-1);

		}
		bt[i] = y;
	}
	lvl[root] = 0;
	recSum(root);
	int tot = sums[root];
	if(sums[root]%3 != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> ids;
	F(i,0,a)
		if(sums[i] == tot/3)
			ids.pb(i);
	for(auto& p : ids)
	{
		parents.clear();
		int nd = comeBack(p, tot/3);


		if(nd != -1)
		{
			if(p < nd)
				swap(p, nd);
			pr2(p + 1, nd + 1);
			return 0;
		}
		F(i,0, a)
		{
			if(parents.find(i) == parents.end() && i != root && i != p)
			{
				if(sums[i] == tot/3)
				{
					if(p > i)
						swap(p, i);
					pr2(p + 1, i + 1);
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}