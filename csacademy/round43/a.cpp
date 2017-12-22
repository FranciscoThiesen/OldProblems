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
	int x;
	vector<int> d1, d2;
	vector<int> prob1(351, 0);
	vector<int> prob2(351, 0);
	rp(i, 6){
		cin >> x;
		d1.pb(x);
	}
	rp(i, 6){
		cin >> x;
		d2.pb(x);
	}
	rp(i, 6){
		rp(j, 6){
			prob1[d1[i]+d2[j]]++;
		}
	}
	int best = 0;
	int prev = -1;
	rp(i, 351){
		if(prob1[i] > prev){
			best = i;
			prev = prob1[i];
		}
	}
	cout << best << endl;

	return 0;
}

