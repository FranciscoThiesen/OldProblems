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
#include <functional>
#include <utility>
#include <string>
#include <string.h>
using namespace std;
#define gcd                         __gcd
#define OR |
#define AND &
#define XOR ^
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
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

long long bc(ll n, ll k)
{
    vector<ll> C(k+1);
    fill(C.begin(), C.end(), 0); 
    C[0] = 1;  // nC0 is 1
 
    for (long long i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (long long j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}

int main()
{
	unsigned long long ans = 0;
	string s;
	cin >> s;
	unordered_map<char, int> freq;
	F(i,0,26)
		freq.insert(mp('a' + i, 0));
	F(i,0,s.size())
	{
		freq[s[i]]++;
	}
	unordered_set<char> jaFoi;
	F(i,0,s.size()-3)
	{
		char fst = s[i];
		unordered_map<char, int> freq1;
		int last = -1;
		if(freq[fst] > 1 && jaFoi.find(fst) == jaFoi.end())
		{
			F(k,i+1, s.size())
				if(s[k] == fst)
					last = k;
			if(last > i + 2)
			{
				F(j, i+1, min((int)last+1,(int)s.size()))
				{
					if(freq1.find(s[j]) == freq1.end())
						freq1.insert(mp(s[j], 1));
					else
						freq1[s[j]]++;
					if(s[j] == fst && j > i+2)
					{
						for(auto& p : freq1)
						{

							if(p.first == fst && p.second >= 3)
							{	
								ans += (bc(p.second-1, 2)%1000000007);
							}
							else if(p.first != fst && p.second >= 2)
							{
								ans += (bc(p.second, 2)%1000000007);
							}
						}
					}

				}
			}
		}
		freq1.clear();
	}
	cout << ans%1000000007 << endl;
	return 0;
}