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
#define endl '\n'
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	char lst = '-';
	string tmp;
	string rep = "***";
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] != 'g' && s[i]!= 'o')
		{
			if(!tmp.empty())
			{
				if(tmp.size()>= 3 &&(tmp.size() == 3 || tmp.size()%3 == 2) && tmp[tmp.size()-1] == 'o')
				{
					ans += rep;
					tmp.clear();
				}
				else if(tmp.size()-1 >= 3 && (tmp.size()-1  == 3 || (tmp.size())%3-1 == 2) && tmp[tmp.size()-1] == 'g')
				{
					ans += rep;
					ans += 'g';
				}
				else
				{	
					ans += tmp;
				}
				tmp.clear();
			}
			ans += s[i];
		}
		else if(s[i] == 'o' && lst != 'o')
		{
			tmp += s[i];		
		}
		else if(s[i] == 'o' && lst == 'o')
		{
			if(tmp.size() >= 3 && (tmp.size()  == 3 || (tmp.size())%3 == 2))
			{
				ans += rep;
				ans += s[i];
			}
			tmp.clear();
			tmp += s[i];		
		}
		else if(s[i] == 'g')
		{
			if(lst == 'o')
			{
				tmp += s[i];
			}
			else if(lst == 'g')
			{
				if(tmp.size()-1 >= 3 && (tmp.size()-1  == 3 || (tmp.size())%3-1 == 2))
				{
					ans += rep;
					ans += s[i];
				}
				ans += s[i];
				tmp.clear();
			}
			else(lst != 'o' && lst != 'g')
			{
				ans += s[i];
			}
		}
		lst = s[i];	
	}
	if(!tmp.empty())
	{
		if(tmp[tmp.size()-1] == 'g')
		{
			if(tmp.size()-1 >= 3 && (tmp.size()-1  == 3 || (tmp.size())%3-1 == 2))
			{
				ans += rep;
				ans += 'g';
			}
			ans += 'g';

		}
		else
		{
			if(tmp.size() >= 3 && (tmp.size() == 3 || (tmp.size())%3 == 2))
			{
				ans += rep;
			}

		}	
	}
	cout << ans << endl;
	return 0;
}