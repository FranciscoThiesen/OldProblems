/*input
1 2 0
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int (i) = (a); (i) < (n); ++(i))
#define per(i,a,n) for(int (i) = (n-1); (i) >= (a); --(i))
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define SZ(a) ((int)(a.size()))
#define init() ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 1000000007;
typedef long double ld;
ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

int fd(int numr, int denr, int find)
{
    int rem = numr%denr;
    rep(i,0,10000)
    {
        rem = rem*10;
        int res_part = rem / denr;
        if(res_part == find){
        	return i+1;
        } 
        // Update remainder
        rem = rem % denr;
    }
 	
    return -1;
}
 

int main(){
	int a, b, c;
	init();
	cin >> a >> b >> c;
	printf("%d\n", fd(a,b,c));
	return 0;
}

