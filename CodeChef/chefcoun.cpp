/*input
99999
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define rp(i, a) for(int (i) = (0); (i) < (a); ++(i))

typedef vector<int> vi;
typedef long long ll;

int wrongSolver(std::vector <unsigned int>& a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	//cout << prefSum[where-1] << " " << sufSum[where-1] << endl;
	//cout << prefSum[where-1] + sufSum[where-1] << endl;
	return where;
}

int rightSolve(std::vector<unsigned int>& a){
	int n = a.size();
	std::vector<ll> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	ll mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		ll val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	//cout << prefSum[where-1] << " " << sufSum[where-1] << endl;
	//cout << prefSum[where-1] + sufSum[where-1] << endl;
	return where;
}

int main(){
	int n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<uint> vec(n);
		ll mx = 4294967296 - (n-80000);
		ll resto = (mx % 80000);
		unsigned int k = mx/80000;
		//cout << k << endl;
		ll tmp;
		for(int i = 0; i < n; ++i){
			if(i == 79999){
				tmp = (4294967296 - (80001*k) - 19991)/2;
				vec[i] = tmp;
			}
			else if(i < 80000){
				vec[i] = k;
				if(resto--){
					vec[i]++;
				}
			}
			else vec[i] = 1;
		}

		// cout << wrongSolver(vec) << endl;
		
		// cout << rightSolve(vec) << endl;
		for(int i = 0; i < n; ++i)
		 	cout << vec[i] << " ";
		cout << endl;
	}
	// vamos escolher o ponto medio para ter o overflow
	 
	return 0;
}
