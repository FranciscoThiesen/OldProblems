/*input

*/
#include <bits/stdc++.h>
using namespace std;
#define gcd                         __gcd
#define lcm(a, b) ((a*b)/gcd(a,b))
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
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

bool isNorthPole(ll x)
{
	if(x%40000 == 20000)
		return true;
	return false;
}

bool isSouthPole(ll x)
{
	if(x%40000 == 0)
		return true;
	return false;
}

bool crossNorthPole(ll x, ll dx)
{
	if(dx > 20000-x)
		return true;
	return false;
}

bool crossSouthPole(ll x, ll dx)
{
	if(x > 0 && dx < 0)

}
int main()
{
	int n;
	cin >> n;
	ll posY = 20000;
	pos = true;
	F(i,0,n)
	{
		string s;
		int x;
		cin >> x >> s;
		if(isSouthPole(poxX, posY) && s != "North")
		{
			pos = false;
			break;
		}
		if(isNorthPole(poxX, posY) && s != "South")
		{
			pos = false;
			break;
		}
		if(s == "South")
			posY -= x;
		else if(s == "North")
			posY += x;
		else if(s == "East")
		{
			posY += x;
		}
		else if(s == "West")
		{	
			posY -= x;
		}
	}

	return 0;
}