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
#define MAXN 101
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

char arena[MAXN][MAXN];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 1, m = 1, s = 1;
	while(n + m + s > 0)
	{
		int robotLin = -1;
		int robotCol = -1;
		int robotDir = -1; // 0 leste, 1 sul, 2 oeste, 3 norte
		cin >> n >> m >> s;
		if(n + m + s == 0)
			break;
		int ans = 0;
		//leitura das posicoes
		for(int linha = 0; linha < n; ++linha)
		{
			string x;
			cin >> x;
			for(int coluna = 0; coluna < m; ++coluna)
			{
				arena[linha][coluna] = x[coluna];
				if(robotDir == -1)
				{
					if(x[coluna] == 'N')
					{
						robotLin = linha;
						robotCol = coluna;
						robotDir = 3;
					}
					else if(x[coluna] == 'O')
					{
						robotLin = linha;
						robotCol = coluna;
						robotDir = 2;
					}
					else if(x[coluna] == 'S')
					{
						robotLin = linha;
						robotCol = coluna;
						robotDir = 1;
					}
					else if(x[coluna] == 'L')
					{
						robotLin = linha;
						robotCol = coluna;
						robotDir = 0;
					}
					
				}
			}
		}
		string ins;
		cin >> ins;
		for(auto& p : ins)
		{
			if(p == 'F')
			{
				if(robotDir == 0) // leste 
				{
					if(robotCol < m-1)
					{
						if(arena[robotLin][robotCol+1] != '#')
						{
							robotCol++;
							if(arena[robotLin][robotCol] == '*')
							{
								ans++;
								arena[robotLin][robotCol] = '.';
							}
						}
					}
				}
				else if(robotDir == 1)//sul
				{
					if(robotLin < n-1)
					{
						if(arena[robotLin+1][robotCol] != '#')
						{
							robotLin++;
							if(arena[robotLin][robotCol] == '*')
							{
								ans++;
								arena[robotLin][robotCol] = '.';
							}

						}
					}
				}
				else if(robotDir == 2)//oeste
				{
					if(robotCol > 0)
					{
						if(arena[robotLin][robotCol-1] != '#')
						{
							robotCol--;
							if(arena[robotLin][robotCol] == '*')
							{
								ans++;
								arena[robotLin][robotCol] = '.';
							}

						}
					}
				}
				else if(robotDir == 3)//norte
				{
					if(robotLin > 0)
					{
						if(arena[robotLin-1][robotCol] != '#')
						{
							robotLin--;
							if(arena[robotLin][robotCol] == '*')
							{
								ans++;
								arena[robotLin][robotCol] = '.';
							}

						}
					}
				}
			}
			if(p == 'D')
			{
				robotDir = (robotDir+1)%4; 
			}
			if(p == 'E')
			{
				if(robotDir == 0)
					robotDir = 3;
				else
					robotDir--;
			}
			
		}
		cout << ans << endl;	
	}
	return 0;
}
