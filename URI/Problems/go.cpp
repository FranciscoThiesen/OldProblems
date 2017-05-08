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
#define MAXN 500
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

int main()
{
	int n, p;
	cin >> n >> p;
	int x, y;
	int tab[MAXN][MAXN] = {{0}};
	F(i,0,p)
	{
		cin >> x >> y;
		tab[x-1][y-1] = 1; // 1 para pecas pretas
	}
	F(i,0,p)
	{
		cin >> x >> y;
		tab[x-1][y-1] = 2;// 2 para pecas brancas
	}

	F(y,0,n)
	{
		F(x,0,n)
		{
			printf("%d ", tab[x][y]);
		}
		printf("\n");
	}
	int tot_brancas = 0;
	int tot_pretas = 0;
	vector<int> accu(n,0);
	F(col, 0, n) // coluna que vai acumular as outras
	{
		//inicializando a coluna que vai acumular as outras
		F(k,0,n)
			accu[k] = tab[col][k];

		//para cada uma das outras colunas, eu vou acumular elas no vetor accu
		F(nxt, col+1, n)
		{
			F(y,0,n)
			{	
				if(accu[y] == 0)
					accu[y] = tab[nxt][y];
				else if(accu[y] == 1 && tab[nxt][y] == 2)
					accu[y] = -11;
				else if(accu[y] == 2 && tab[nxt][y] == 1)
					accu[y] = -1;
			}
			//quantas celulas adjacentes vou precisar para formar um quadrado 
			int adj = col - nxt + 1;
			int sz = 0;
			int color = 0;
			F(j, 0, n)
			{
				if(accu[j] == 1)
				{
					if(color == 2)
					{
						sz = 1;
						color = 1;
					}
					if(color == 0)
					{
						color = 1;
						sz++;
						if(sz >= adj)
							tot_pretas += sz-adj+1;
					}
					else
					{
						sz++;
						if(sz > adj)
							tot_pretas++;
					}
				}
				else if(accu[j] == 2)
				{
					if(color == 1)
					{
						sz = 1;
						color = 2;
					}
					if(color == 0)
					{
						color = 2;
						sz++;
						if(sz >= adj)
							tot_brancas += sz-adj+1;
					}
					else
					{
						sz++;
						if(sz > adj)
							tot_brancas++;
					}
				}
				else if(accu[j] == -1)
				{
					color = 0;
					sz = 0;
				}
				else
				{
					sz++;
					if(color == 1)
					{
						if(sz > adj)
							tot_pretas++;
					}
					else if(color == 2)
				    {
				    	if(sz > adj)
							tot_brancas++;
					}
				}
			}
		}	
	}
	printf("%d %d\n", tot_brancas, tot_pretas);
	return 0;
}
