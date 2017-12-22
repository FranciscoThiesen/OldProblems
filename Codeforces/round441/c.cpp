/*input
20
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

int digSum(int x){
	string s = to_string(x);
	int sum = 0;
	for(const char& c : s){
		sum += c - '0';
	}
	return sum;
}
int main(){
	int n;
	scanf("%d", &n);
	int tot = 0;
	vector<int> nums;
	int st = max(0, n-200);
	fr(i, st, n){
		if(i + digSum(i) == n){
			tot++;
			nums.pb(i);
		}
	}
	cout << tot << endl;
	sort(all(nums));
	for(const int& v : nums)cout << v << endl;
	return 0;
}

