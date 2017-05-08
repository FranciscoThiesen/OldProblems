#include <bits/stdc++.h>
#include <stdlib.h>
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

// int solve(int n, int xi, int yi)
// {
// 	std::ios::sync_with_stdio(false);
// 	unordered_set<int> toGo;
// 	for(int i = 1; i <= n*n; ++i)
// 		toGo.insert(i), cout << i << endl;
// 	cout << toGo.size() << endl;
// 	vi path;
// 	int begin = (yi)*n + xi + 1;
// 	int x = xi;
// 	int y = yi;
// 	while(!toGo.empty())
// 	{
// 		int mov = 1;
// 		int cont = 1;
// 		if(cont%4 == 1)
// 		{
// 			for(int j = 0; j < mov; ++j)
// 			{
// 				cout << "i = " << j << " mov = " << mov << endl;
// 				x++;
// 				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
// 					path.pb(y*n + x + 1), toGo.erase(y*n + x + 1);
// 			}
// 			cont++; 	
// 		}
// 		else if(cont%4 == 2)
// 		{
// 			F(i,0,mov)
// 			{
// 				y++;
// 				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
// 					path.pb(y*n + x + 1), toGo.erase(y*n + x + 1);
// 			}
// 			mov++;
// 			cont++;
// 		}
// 		else if(cont%4 == 3)
// 		{
// 			F(i,0,mov)
// 			{
// 				x--;
// 				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
// 					path.pb(y*n + x + 1), toGo.erase(y*n + x + 1);
// 			}
// 			cont++;
// 		}
// 		else
// 		{
// 			F(i,0,mov)
// 			{
// 				y--;
// 				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
// 					path.pb(y*n + x + 1), toGo.erase(y*n + x + 1);
// 			}
// 			cont++;
// 			mov++;
// 		}
// 		cout << " x = " << x << "   y = " << y << endl;
// 		_sleep(2000);
// 	}
// 	F(i,0,path.size())
// 		if(i != path.size()-1)
// 			cout << i << " ";
// 		else
// 			cout << i << endl;
// 	cout << path.size() << endl;		
// 	return 0;
	
// }
int main()
{
	std::ios::sync_with_stdio(false);
	int n, xi, yi;
	cin >> n >> xi >> yi;
	unordered_set<int> toGo;
	for(int i = 1; i <= n*n; ++i)
		toGo.insert(i);
	vi path;
	int begin = (yi)*n + xi + 1;
	toGo.erase(begin);
	path.pb(begin);
	int x = xi;
	int y = yi;
	int mov = 1;
	int cont = 1;
	int total = 1;
	while(!toGo.empty())
	{
		
		if(cont%4 == 1)
		{
			for(int j = 0; j < mov; ++j)
			{
				x++;
				total++;
				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
				{
					path.pb(y*n + x + 1);
					toGo.erase(y*n + x + 1);
					if(toGo.empty())
						break;
				}
			}
			cont++;
		}
		else if(cont%4 == 2)
		{
			F(i,0,mov)
			{
				y++;
				total++;
				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
				{
					path.pb(y*n + x + 1);
					toGo.erase(y*n + x + 1);
					if(toGo.empty())
						break;
				}
			}
			mov++;
			cont++;
		}
		else if(cont%4 == 3)
		{
			F(i,0,mov)
			{
				x--;
				total++;
				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
				{
					path.pb(y*n + x + 1);
					toGo.erase(y*n + x + 1);
					if(toGo.empty())
						break;
				}
			}
			cont++;
		}
		else
		{
			F(i,0,mov)
			{
				y--;
				total++;

				if(y <= n-1 && x <= n-1 && x > -1 && y > -1)
				{
					path.pb(y*n + x + 1);
					toGo.erase(y*n + x + 1);
					if(toGo.empty())
						break;
				}
			}
			cont++;
			mov++;
		}

	}
	F(i,0,path.size())
		if(i != path.size()-1)
			cout << path[i] << " ";
		else
			cout << path[i] << endl;
	cout << total << endl;		
	return 0;

}       	