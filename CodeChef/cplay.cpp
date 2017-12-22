/*input

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

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }
string a;

void doit(){
	int w1 = 0, w2 = 0;
	bool final = false;
	int tam = SZ(a), need, can;
	int i;
	for(i = 1; i <= tam; ++i){
		if(i%2) w1 += a[i-1] - '0';
		else w2 += a[i-1] - '0';
		if(i == 10){
			if(w1 > w2){
				final = true;
				break;
			}
			if(w2 > w1){
				final = true;
				break;
			}
		}
		else if(i < 10){
			if(i%2){
				if(w1 > w2){
					need = w1-w2;
					can = (10 - i + 1) >> 1;
					if(can < need){
						final = true;
						break;
					}
				}
				else if(w2 > w1){
					need = w2-w1;
					can = (10 - i) >> 1;
					if(can < need){
						final = true;
						break;
					}
				}
			}
			else if(!(i%2)){
				if(w1 > w2){
					need = w1-w2;
					can = (10 - i) >> 1;
					if(can < need){
						final = true;
						break;
					}
				}
				else if(w2 > w1){
					need = w2-w1;
					can = (10 - i) >> 1;
					if(can < need){
						final = true;
						break;
					}
				}
			}
		}
		else if(i <= 20){
			if(!(i%2)){
				if(w1 > w2){
					final =true;
					break;
				}
				else if(w2 > w1){
					final = true;
					break;
				}
			}
		}
		else break;
	}
	if(w1 > w2)cout << "TEAM-A " << i <<  endl;
	else if(w2 > w1) cout << "TEAM-B " << i << endl;
	else cout << "TIE"  << endl;
}



int main(){
	init();
	while(cin >> a){
		doit();
	}
	return 0;
}
