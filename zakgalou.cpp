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
#include <functional>
#include <unordered_set>
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
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n", n); }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
const int INF = 0x3F3F3F3F;
vvii AdjList(1010);
vi CostPerRoom(1001,0);//indice corresponde ao no -> soma dos custos minimos para matar os monstros presentes em cada salao
//vi CostPerMonsterLife(1001, INF);// custo minimo em funcao da vida do monstro
//vvi MonstersPerRoom(1001); Parece redundante
vi MinMP(1001, INF);
vii Magia;// precisa estar ordenado
vi Dist(1001, INF);
vii Edges;

int knapsack(int hp)
{
	if (MinMP[hp] != INF)
		return MinMP[hp];
	for (int i = 0; i < Magia.size(); ++i)
	{	
		if(hp - Magia[i].second >= 0) 
			MinMP[hp] = min(MinMP[hp], MinMP[hp - Magia[i].second] + Magia[i].first);
		else
			MinMP[hp] = min(MinMP[hp], MinMP[0] + Magia[i].first);
	}
	return MinMP[hp];
}

// int minMana(int hp)
// {
// 	for (int i = 0; i < MinMP.size(); ++i)
// 		if (MinMP[i] >= hp)
// 			return i;
// }

int main()
{
	int magias = 1; 
	int nodes = 1;
	int edges = 1; 
	int monsters = 1;
	while (magias + nodes + edges + monsters != 0)
	{
		cin >> magias >> nodes >> edges >> monsters;
		if (magias + nodes + edges + monsters == 0)
			break;
		
		
		for (int j = 0; j < magias; j++)
		{
			int a, b;
			cin >> a >> b;
			Magia.push_back(mp(a, b));
		}
		sort(Magia.begin(), Magia.end());
		for (int k = 0; k < edges; k++)
		{
			int x, y;
			cin >> x >> y;
			Edges.push_back(mp(x,y));
		}
		//KnapSack
		MinMP[0] = 0;
		for (int q = 1; q < 1001; q++)
			knapsack(q);
		//fim knapsack
		//Calculando qual o minimo necessario para passar por cada quarto
		for (int m = 0; m < monsters; m++)
		{
			int h, p;
			cin >> h >> p;
			CostPerRoom[h] += MinMP[p];
		}
		//preenchendo o grafo de acordo com os valores calculados anteriormente 
		for(int i = 0; i < edges; i++)
		{
			ii e = Edges[i];
			AdjList[e.first].push_back(mp(CostPerRoom[e.second], e.second));
			AdjList[e.second].push_back(mp(CostPerRoom[e.first], e.first));
		}
		//Dijkstra
		Dist[1] = 0;
		priority_queue<ii, vii, greater<ii> > q;
		q.push(mp(0,1));
		while (!q.empty())
		{
			ii front = q.top();
			q.pop();
			int d = front.first;
			int u = front.second;
			if(d > Dist[u])
				continue;
			for (int i = 0; i < AdjList[u].size(); ++i)
			{
				ii v = AdjList[u][i];
				if (Dist[u] + v.first < Dist[v.second])
				{
					Dist[v.se] = Dist[u] + v.fi;
					q.push(mp(Dist[v.se], v.se));
				}
			}
		}
		if (Dist[nodes] == INF)
			cout << "-1" << endl;
		else
			cout << Dist[nodes] + CostPerRoom[1]<< endl;
		Magia.clear();
		Edges.clear();
		fill(Dist.begin(), Dist.end(), INF);
		fill(CostPerRoom.begin(), CostPerRoom.end(), 0);
		//fill(CostPerMonsterLife.begin(), CostPerMonsterLife.end(), INF);
		fill(MinMP.begin(), MinMP.end(), INF);
		for (int i = 0; i < AdjList.size(); ++i)
			AdjList[i].clear();
	}
	return 0;
}