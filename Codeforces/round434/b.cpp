/*input
1 0
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

vi flo(101, -1);
	
int solve(int n){
	set<int> ans;
	for(int i = 1; i < 100; ++i){
		bool ok = true;
		int calc;
		for(int j = 1; j <= 100; ++j){
			calc = (j-1)/i + 1;
			if(flo[j] != -1 && flo[j] != calc){
				ok = false;
				break;
			}
		}
		if(ok){
			ans.insert((n-1)/i + 1);
		}
	}
	if(ans.size() == 1) return *(ans.begin());
	else return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	rp(i, m){
		int a, b;
		scanf("%d %d", &a, &b);
		flo[a] = b;
	}
	if(flo[n] != -1){
		cout << flo[n] << endl;
		return 0;
	}
	else{
		cout << solve(n) << endl;
	}
	return 0;
	
}

