#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
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
#define INF 100000001
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
#define MAXN 2001
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<vii> vpii;
vii Points(MAXN);
const double EPS = 1e-10;
inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
//vector<double> Dist(MAXN, -1);

double Dst(int x1, int y1, int x2, int y2)
{
	double deltaX = abs(x1 - x2);
	double deltaY = abs(y1 - y2);
	return sqrt((deltaX * deltaX) + (deltaY * deltaY));
}
int main()
{
	int d = 1;
	while(true)
	{

		int nodes;
		unsigned long long int total = 0;
		getI(nodes);
		if(!nodes)
		    break;
		vector<vector<double> > Distance(nodes, vector<double>(nodes,INF));
		F(j,0,nodes)
		{
			int x, y;
			cin >> x >> y;
			Points[j] = mp(x,y);
		}
		F(k,0, nodes)
		{
			F(y,0, nodes)
			{
				if(k == y)
					Distance[k][y] = 0;
				else if(Distance[k][y] == INF && Distance[y][k] == INF)
				{
					Distance[k][y] = Dst(Points[k].fi, Points[k].se,Points[y].fi, Points[y].se);
				}
				else
					Distance[k][y] = Distance[y][k];

			}
		}
		F(e, 0, nodes)
		{
			sort(Distance[e].begin(), Distance[e].end());
			double LastNum = Distance[e][0];
			int seq = 1;
			F(z,1,nodes)
			{
				if(cmp(Distance[e][z],LastNum) == 0 && z == nodes-1)
				{
					seq++;
					total += ((1+ (seq-1))/2.0) * (seq-1);
					break;
				}
				else if(cmp(Distance[e][z], LastNum) == 0 && Distance[e][z] != 0)
				{
					seq++;
				}
				else//(Distance[e][z] != LastNum)
				{
				        total += (seq * (seq-1))/2;
				        LastNum = Distance[e][z];
					seq = 1;
				}

			}
			fill(Distance[e].begin(), Distance[e].end(),INF);
		}	
		Points.clear();
		cout << total << endl;
		d++;
	}
	return 0;
}
