#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int, int> ii;

int main(){
	int n;
	cin >> n;
	vi c(n);
	vector<ii> numPos(n);
	for(int i = 0; i < n; ++i){
		cin >> c[i];
		numPos[i] = mp(c[i], i+1);
	}
	sort(all(numPos));
	ll resp = 0;
	for(int i = 0; i < n-1; ++i){
		int curPos = numPos[i].se;
		int nxtPos = numPos[i+1].se;
		int inc = min(abs(curPos - nxtPos), min(n - curPos + nxtPos, curPos + (n - nxtPos)));
		resp += inc;
	}
	cout << resp << endl;
}