/*input
3 1 7 2 1
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

int mat[101][101] = {{0}};

int main()
{
	IOS
	cin.tie();
	int n, m, x, y;
	ull k;
	cin >> n >> m >> k >> x >> y;
	if(n == 1)
	{
		cout << (k-1)/m + 1<< " " << (k-m)/m + 1 << " " << (k-y)/m + 1 << endl;
		return 0;
	}
	if(n == 2)
	{
		cout << (k-1)/(m*n) + 1 << " " << (k-(m*n))/(m*n) + 1<< " " << (k - (x-1)*m - y)/(m*n) + 1 << endl;
		return 0;
	}
	int tot = n*m;
	// o menos visitado esta sempre em n-1
	// quantas vezes o ultimo de n-1 foi visitado
	ull mn;
	ull fiVist = m*n;
	//demora para revisitar
	ull mx = 0;

	
	ull period = tot + (n-2)*m;
	//total de vezes que visitou o ultimo
	mn = (k - fiVist)/period + 1;
	
	ull fi = (k- m)/period + 1;
	if(k < tot)
	{
		cout << 1 << " " << 0 << " " << max((ull)0, (x*y)/k) << endl;
		return 0;
	}
	else
	{// sera que o ultimo da primeira fileira foi mais visitado que o ultimo?	
		
		if(fi > mn)
		{
			ull tmp1 = k - m;// tirando a primeira passada
			if(tmp1%period == 0)
			{
				mx = ((fi-1)*2); 
			}
			else
				mx = ((fi-1)*2) + 1;	

		}
		else
		{
			ull tmp2 = k - tot;
			if(tmp2%period == 0)
			{
				mx = (2*mn)-1;
			}
			else
				mx = (2*mn);
		}
	}
	ull serg = 0;
	if(x == 1)
	{
		serg = (k- y)/period + 1;
	}
	else if(x == n)
	{
		serg = (k - ((n-1)*m) - y)/period + 1;
	}
	else
	{
		ull distSergFi = (x-2)*m + y;
		ull distSergSe = (n-x-1)*m + y;
		//cout << distSergFi << " " << distSergSe << endl;
		if(fi > mn)
		{
			ull tmp1 = k - m;// tirando a primeira passada
			if(tmp1%period >= distSergSe)
			{
				serg = ((fi-1)*2) + 1; 
			}
			else
				serg = ((fi-1)*2);	

		}
		else
		{
			ull tmp2 = k - tot;
			if(tmp2%period >= distSergSe)
			{
				serg = (2*mn);
			}
			else
				serg = (2*mn)-1;
		}		
	}
	cout << max(mx, serg) << " " << min(mn,serg) << " " << serg << endl;

	return 0;
}