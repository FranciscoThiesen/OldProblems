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


typedef pair<int, int> bezout;
bezout find_bezout(int x, int y) { if (y == 0) return bezout(1, 0); bezout u = find_bezout(y, x % y); return bezout(u.second, u.first - (x/y) * u.second);
}


int mod(int x, int m) { return x % m + (x < 0) ? m : 0; }
int solve_mod(int a, int b, int m) { if (m < 0) return solve_mod(a, b, -m); if (a < 0 || a >= m || b < 0 || b >= m)
 return solve_mod(mod(a, m), mod(b, m), m); bezout t = find_bezout(a, m); int d = t.first * a + t.second * m; if (b % d) return -1; else return mod(t.first * (b / d), m);
}

int main()
{
	int l;
	getI(l);
	int cur = 2;
	for(int i = 1; i <= l; ++i)
	{
		int x = solve_mod(i+1, 0, i);
		cout << i + 1  << " " << i << endl;
		cout << x << " a*x = " <<(i+1)*x;			
		unsigned long long sqr = (i+1)*x*(i+1)*x;
		cout << (sqr - cur)/i << endl;
		cur = (i+1)*x;
	}                                                               
	return 0;
}