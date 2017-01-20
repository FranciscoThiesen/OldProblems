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


int search(vector<int>& array, int start_idx, int end_idx, int search_val) {

   if( start_idx == end_idx )
      return array[start_idx] <= search_val ? start_idx : -1;

   int mid_idx = start_idx + (end_idx - start_idx) / 2;

   if( search_val < array[mid_idx] )
      return search( array, start_idx, mid_idx, search_val );

   int ret = search( array, mid_idx+1, end_idx, search_val );
   return ret == -1 ? mid_idx : ret;
}

int main()
{
	ull n, m, k;
	IOS
	cin >> n >> m >> k;
	int initialS, mana;
	cin >> initialS >> mana;
	vector<int> betterTime;
	vector<ii> timePrice;
	F(i,0,m)
	{
		int x;
		cin >> x;
		betterTime.pb(x);
	}
	F(i,0,m)
	{
		int p;
		cin >> p;
		timePrice.pb(mp(p, betterTime[i]));
	}
	vector<int> numP;
	F(i,0,k)
	{
		int np;
		cin >> np;
		numP.pb(np);
	}
	vector<int> priceII;
	F(i,0,k)
	{
		int y;
		cin >> y;
		priceII.pb(y);
	}

	// para cada ekenebti de time Price, tenho que fazer bb no priceII;
	ull ans = n*initialS;
	for(int i = 0; i < timePrice.size(); ++i)
	{
		if(mana < timePrice[i].first)
			continue;
		int idx = search(priceII, 0, (int)priceII.size(), mana - timePrice[i].first);
		if(idx != -1)
		{
			ans = min(ans, (n - numP[idx])*timePrice[i].second);
		}
		else
			ans = min(ans, n*timePrice[i].second);
	}
	for(int j = 0; j < numP.size(); ++j)
	{
		if(priceII[j] <= mana)
			ans = min(ans, (n-numP[j])* initialS);
	}
	cout << ans << endl;
	return 0;
}