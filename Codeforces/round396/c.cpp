/*input
10
abcdeabcde
5 5 5 5 4 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/

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

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

const ull mod = 1000000007;
int main()
{
	IOS
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi freq(26);
	F(i,0,26)
		cin >> freq[i];

	int longest = -1;
	ull ans = 0;
	int minSubs = 0;
	for(int i = 0; i < n; ++i)
	{
		int cur = 1;
		int tot = freq[s[i]-'a'];
		//cout << s[i] << " " << tot << endl;
		for(int j = i+1; j < min((int)s.size(), i+tot) ; ++j)
		{
			if(freq[s[j]-'a'] >= j-i+1)
			{
				cur++;
			}
			else
				break;
		}
		//cout << cur << " " << i << endl;
		ull inc = modpow((ull)2, (ull)cur-1, mod);
		//cout << inc << endl;
		ans += inc;
		ans %= mod;
		longest = max(cur, longest);
		
	}
	int tot = 0;
	int split = -1;
	for(int i = 0; i < n; ++i)
	{
		int cur = 1;
		int t = freq[s[i]-'a'];
		//cout << s[i] << " " << tot << endl;
		cout << s[i] << " comecando de, " << endl;
		if(i == n-1)
		{
			tot++;
			break;
		}
		for(int j = i+1; j < min((int)s.size(), i+t) ; ++j)
		{
			if(freq[s[j]-'a'] >= j-i+1)
			{
				cur++;
			}
			else
			{
				split = j;
				break;
			}
			split = j;
		}
		if(split == i)
			i++;
		else
			i = split-1;
		//cout << i << endl;
		tot++;
		
	}
	cout << ans << endl;
	cout << longest << endl;
	cout << tot << endl;
	cout << "se fini" << endl;
	return 0;
}