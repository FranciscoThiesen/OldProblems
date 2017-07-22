/*input
abcd
abc
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

vi kmp(string& txt, string& ptt) {
    vi matches;

    // Calculo do vetor auxiliar lps (longest proper prefix
    // which is also suffix).
    vi lps(ptt.size() + 1, -1);

    for (int i = 1; i <= ptt.size(); i++) {
        int pos = lps[i - 1];
        while (pos != -1 and ptt[pos] != ptt[i - 1])
            pos = lps[pos];
        lps[i] = pos + 1;
    }    

    // String search.
    int sp = 0;
    int kp = 0;
    while(sp < txt.size()) {
        while (kp != -1 and (kp == ptt.size() || ptt[kp] != txt[sp]))
            kp = lps[kp];
        kp++; sp++;
        if (kp == ptt.size())
            matches.push_back(sp - ptt.size());
    }
    return matches;
}

int main()
{
	IOS
	int a;
	string s;
	string s2;
	cin >> s >> s2;
	if(s == s2)
		cout << -1 << endl;
	else
		cout << max(s.size(), s2.size()) << endl;
	return 0;
}