/*input
4
1 3 4 2
*/
#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int maxn = 3 * 1e5 + 5;

int arr[maxn];
map<int, int> intervalos;
int fstX = -1;


int main(){
	int n;
	scanf("%d", &n);
	rp(i, n) scanf("%d", &arr[i]);
	
	int fstX = 0;
	cout << 1 << endl;
	intervalos[0] = n-1;
	int totalInterv = 1;
	int firstX = 1e9;
	int kRalho = 0;
	rp(i, n){
		int nw = arr[i]-1;
		kRalho++;
		firstX = min(firstX, nw);
		auto idx = intervalos.upper_bound(nw);
		//cout << "nw = " << nw << endl;
		--idx;
		ii par = *(idx);
		//cout << "intervalo contendo = " << par.fi << " " << par.se  << endl;
		// 3 cases
		if(nw == par.se){
			if(par.fi == par.se){
				intervalos.erase(intervalos.find(par.fi));
				totalInterv--;
			}
			else{
				intervalos[par.fi] = par.se - 1;
			}
		}
		else if(nw == par.fi){
			intervalos.erase(intervalos.find(par.fi));
			if(par.se != par.fi){
				intervalos[par.fi + 1] = par.se;
			}
			else totalInterv--;
		}	
		else{
			intervalos[par.fi] = nw-1;
			intervalos[nw+1] = par.se;
			totalInterv++;
		}
		if(i == n-1){
			cout << 1 << endl;
			return 0;
		}
		auto last = *(intervalos.rbegin());
		int resp = i + 1 - (n-1 - last.se);
		cout << 1 + max(0, resp) << endl;
		//printf("%d\n", 1 + totalInterv);
	}

	return 0;
}

