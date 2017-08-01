// https://www.codechef.com/LTIME43/problems/SUPVIL

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
 
bool isHero(string s)
{
	int sz = s.size();
	if(sz >= 3)
	{
		if(s[sz-1] == 'n' && s[sz-2] == 'a' && s[sz-3] == 'm')
			return true;
	}
	else if(sz >= 5)
	{
		if(s[sz-1] == 'n' && s[sz-2] == 'a' && s[sz-3] == 'm' && s[sz-4] == 'o' && s[sz-5] == 'w')
			return true;
	}
	return false;
}
 
int main()
{
	IOS
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int h = 1;
		int v = 1;
		int x;
		cin >> x;
		bool hero = false;
		bool villain = false;
		while(x--)
		{
			string k;
			cin >> k;
			if(isHero(k))
				h++;
			else
				v++;
			if(h - v >= 2)
			{
				if(!villain)
					hero = true;
			}
			else if(v - h >= 3)
			{
				if(!hero)
					villain = true;
			}
		}
		if(hero)
			cout << "superheroes" << endl;
		else if(villain)
			cout << "villains" << endl;
		else
			cout << "draw" << endl;
 
	}
	return 0;
} 