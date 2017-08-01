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

vector<int> ways(20, 0);

int main(){
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			ways[i+j]++;
		}
	}
	// for(int i = 0; i < 19; ++i)
	// {
	// 	cout << i << "  ways[i] = " << ways[i] << endl;
	// }
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> c(n);
	for(int i = 0; i < n-1; ++i)cin>>c[i+1];

	ull ans = 1;
	bool carry = 0;
	for(int i = n-1; i > 0; --i){
		int dg = s[i] - '0';
		
		if(carry){
			// if(dg == 0 && !c[i]){
			// 	cout << 0 << endl;
			// 	return 0;
			// }
			// else if(dg == 0 && c[i])
			dg--;

		}
		if(c[i]){
			carry = true;
			dg += 10;
		}
		else carry = false;
		//cout << "dg = " << dg << endl;
		if(dg < 0){
			cout << 0 << endl;
			return 0;
		}
		ans *= ways[dg];
	}
	// last digit
	int ld = s[0] - '0';
	if(carry) ld--;
	ans *= ways[ld];
	cout << ans << endl;
	return 0;
}