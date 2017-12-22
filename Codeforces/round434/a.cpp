/*input
123456789 8
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
#define gcd __gcd
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;


ull lcm(ull a, ull b){
	return a*b / gcd(a,b);
}

int main(){
	ll a, b;
	cin >> a >> b;
	ull k = 1;
	rp(i, b) k *= 10;
	cout << lcm(a, k) << endl;	
	return 0;
}

