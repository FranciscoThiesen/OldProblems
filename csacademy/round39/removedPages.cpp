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

main(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; ++i) cin >> p[i];
	int resp = 1;
	sort(all(p));
	for(int i = 1; i < n; ++i){
		if(p[i]%2 == 1)resp++;
		else if(p[i-1] != p[i] - 1) resp++;
	}
	cout << resp << endl;
}