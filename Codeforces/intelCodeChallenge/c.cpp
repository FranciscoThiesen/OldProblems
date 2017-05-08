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
#include <tuple>
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
typedef long long ll;


struct BIT {
    int n;
    vector<ll> bit;
    BIT(int _n) : n(_n+1) {
        bit.resize(n+1, 0);
    }
    void update(int x, ll val) {
        x++;
        for (; x <= n; x += x & -x)
            bit[x] += val;
    }
    ll query(int x) {
        x++;
        ll ret = 0;
        for (; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }
    ll query(int l, int r) {
        return query(r)-query(l-1);
    }
};


int main()
{
	IOS
	cin.tie(0);
	int n;
	cin >> n;
	map<pair<ll, ll>, long long> intervaloValor;
	vector<ll> nums(n);
	BIT arv(n);
	F(i,0,n)
	{
		cin >> nums[i];
		arv.update(i, nums[i]);
	}
	vector<int> dest(n);
	F(i,0,n)
	{
		int x;
		cin >> x;
		dest[i] = x-1;
	}
	map<ll, ll> vals;
	intervaloValor[mp(n-1, 0)] = arv.query(0, n-1);
	//vals[0] = 1;
	vals[arv.query(0, n-1)] = 1;

	for(int i = 0; i < n-1; ++i)
	{
		int p = dest[i];
		auto it = intervaloValor.lower_bound(mp(p, 0));

		int beg = it->fi.se;
		int end = it->fi.fi;
		ll to_rmv = it->se;
		vals[to_rmv]--;
		if(vals[to_rmv] <= 0)
			vals.erase(vals.find(to_rmv));

		//cout << "Achei o intervalo comecando em " << beg << " e terminando em " << end << "     ";
		//cout << "Soma dele = " << to_rmv << endl << endl;
		intervaloValor.erase(it);
		arv.update(p, 0);
		int beg1;
		int beg2;
		int end1;
		int end2;
		ll sum1;
		ll sum2;
		if(end == p && end != beg)
		{
			beg1 = beg;
			end1 = p-1;
			sum1 = arv.query(beg1, end1);
			vals[sum1]++;
			//cout << "novo intervalo 1  comecando em " << beg1 << " e terminando em  " << end1 << endl;
			intervaloValor[mp(end1, beg1)] = (sum1);
		}
		else if(beg == p && beg != end)
		{
			beg1 = beg+1;
			end1 = end;
			sum1 = arv.query(beg1, end1);
			vals[sum1]++;
			//cout << " creu novo intervalo 1  comecando em " << beg1 << " e terminando em  " << end1 << endl;

			intervaloValor[mp(end1, beg1)] = (sum1);


		}
		else if(beg == p && end == p)
		{
			goto fodase;
		}
		else
		{
			beg1 = beg;
			end1 = p-1;
			sum1 = arv.query(beg1, end1);
			beg2 = p+1;
			end2 = end;
			sum2 = arv.query(beg2, end2);
			vals[sum1]++;
			vals[sum2]++;
			//cout << "novo intervalo 1  comecando em " << beg1 << " e terminando em  " << end1 << endl;
			//cout << "novo intervalo 2  comecando em " << beg2 << " e terminando em  " << end2 << endl;
			intervaloValor[mp(end1, beg1)] = (sum1);
			intervaloValor[mp(end2, beg2)] = (sum2);
		}
fodase:

		//cout << "Imprimindo os valores do mapa" << endl;
		//cout << endl;
		//auto it2 = vals.end();
		cout << (*vals.rbegin()).fi << endl;
		// for(auto it3 = vals.rbegin(); it3 != vals.rend(); ++it3)
		// {
		// 	if(it3->second > 0)
		// 	{
		// 		cout << it3->first << endl;
		// 		break;
		// 	}
		// }
	}
	cout << 0 << endl;
	return 0;
}