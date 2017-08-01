// https://www.codechef.com/LTIME43/problems/FLYMODE
/*input
6
10 8 9 3 4 2
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
 
int main()
{
	IOS
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1;
	int cur = 0;
	vector<int> nums(n);
	F(i,0,n)
	{
		cin >> nums[i];
	}
	if(n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	vector<pair<int, bool> > intervals;
	bool up = false;
	int beg = nums[0];
	int ant = nums[1];
	if(nums[1] > nums[0])
	{
		up = true;
		
	}
	F(i,2,n)
	{
		if(nums[i] > ant)
		{
			if(up == true)
			{
				ant = nums[i];
			}
			else
			{
				intervals.pb(mp(min(beg, ant), false));
				intervals.pb(mp(max(beg, ant), true));
				beg = ant;
				ant = nums[i];
				up = true;
			}
		}
		else if(nums[i] < ant)
		{
			if(!up)
			{
				ant = nums[i];
			}
			else 
			{
				intervals.pb(mp(min(beg, ant), false));
				intervals.pb(mp(max(beg, ant), true));
				beg = ant;
				ant = nums[i];
				up = false;
			}
		}
	}
	intervals.pb(mp(min(beg, ant), false));
	intervals.pb(mp(max(beg, ant), true));
	sort(intervals.begin(), intervals.end());
	for(int i = 0; i < intervals.size(); ++i)
	{
		if(intervals[i].se == false)
			cur++;
		else
			cur--;
		ans = ((cur > ans)? cur : ans);
	}
	cout << ans << endl;
	return 0;
} 