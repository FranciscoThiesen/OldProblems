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
#include <functional>
using namespace std;
#define gcd                         __gcd
#define OR |
#define AND &
#define XOR ^
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow)while(testow--) //for multilple cases problems
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
#define INF 100000001
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
typedef vector<vii> vvii;


int main()
{
	int n;
	getI(n);
	vvii AdjList(n);
	int arr[n];
	F(i,0,n)
		scanf("%d", &arr[i]);
	F(j,0,n)
	{
		int x, y;
		getII(x,y);
		AdjList[j].pb(mp(x,y)); // adicionando o pair nó + custo a lista de adjacencia
	}
	vi visitOrder;
	visitOrder.pb(0);
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(int elem = 0; elem < AdjList[node].size(); ++elem)
		{
			if(visited[AdjList[node][elem].fi] == false)
			{
				visited[AdjList[node][elem].fi] = true;
				visitOrder.pb(AdjList[node][elem].fi);
				q.push(AdjList[node][elem].fi);
			}
		}
	}
	vector<bool> eliminado(n, false);
	int ans = 0;
	vi Dist(n, INF);
	for(int no = 0; no < visitOrder.size(); ++no)
	{
		if(eliminado[no] == false || eliminado[no] == true)
		{
			fill(Dist.begin(), Dist.end(), INF);
			queue<int> fila;
			int root = visitOrder[no];
			Dist[root] = 0;
			fila.push(root);
			while(!fila.empty())
			{
				int u = fila.front();
				fila.pop();
				F(vertex, 0, AdjList[u].size())
				{
					if(eliminado[u] == true)
						eliminado[AdjList[u][vertex].fi] = true;
					if(Dist[AdjList[u][vertex].fi] == INF)
					{
						Dist[AdjList[u][vertex].fi] = Dist[u] + AdjList[u][vertex].se;
						if(Dist[AdjList[u][vertex].fi] > arr[AdjList[u][vertex].fi])
						{
							eliminado[AdjList[u][vertex].fi] = true;
						}
						fila.push(AdjList[u][vertex].fi);
						if(eliminado[AdjList[u][vertex].fi] == true)
							ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;

}