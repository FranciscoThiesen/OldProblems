/*input
abacaba
ubuduba
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
const int maxn = 1e5 + 5;
ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

const int Z = 26;

int freq[Z];
string a, b;
ll fat[maxn], invFat[maxn];
ll ans = 0;


main(){
  fat[0] = invFat[0] = 1;
  init();
  rep(i,1,maxn){
    fat[i] = (fat[i-1] * i) % mod;
    invFat[i] = powmod(fat[i], mod - 2);
  }
  cin >> a >> b;
  int sz = SZ(a);
  
  for(const char& c : a) freq[c-'a']++;
  rep(i,0,sz){
    int st = a[i] - '0';
    int nd = b[i] - '0';
    rep(k, st + 1, nd){
      cout << " k = " << k << endl;
      ll pos = fat[sz-i-1];
      freq[k]--;
      cout << "pos = " << pos << endl;
      rep(q,0,26) pos = (pos * invFat[freq[q]]) % mod;
      cout << "pos = " << pos << endl;
      ans = (ans + pos) % mod;
      freq[k]++;
      cout << "ans = " << ans << endl;
    }
    freq[a[i]-'0']--;
  }
  cout << ans << endl;
  return 0;
}



