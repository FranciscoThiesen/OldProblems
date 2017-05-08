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
#include <deque>
#include <tuple>

using namespace std;

#define gcd                         __gcd

#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest


#define fr(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define fu(i, n) fr(i,0,n)

#define sc(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define pr(a) printf("%d\n", a)
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)

#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))

#define getS(x) scanf("%s", x) //get a char* string

#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define sz(x) ((int)((x).size()))

#define remax(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define remin(a,b) (a)=min((a),(b));

#define snuke(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define rall(c) (c).rbegin(), (c).rend()

#define IOS ios_base::sync_with_stdio(0) //to synchronize the input of cin and scanf
#define INF 1001001001

#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back

// for debug
inline void pisz(int n) { printf("%d\n",n); }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000

//for vectors
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;

const double PI = 3.1415926535897932384626;
const double inf = 1.0/0.0;

template<typename T>
T lcm(T a, T b)
{
	return (a*b)/gcd(a, b);
}

int main()
{
	
}