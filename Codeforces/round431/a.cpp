/*input
4
3 9 9 3
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

int main(){
	int n;
	cin >> n;
	vector<int> vec(n);
	rp(i, n) cin >> vec[i];
	if(vec[0]%2 == 1 && vec[n-1]%2 == 1 && n%2 == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

