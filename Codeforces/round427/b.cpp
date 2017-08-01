/*input
3
11
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
	string s;
	cin >> n >> s;
	int curSum = 0;
	for(char c : s) curSum += c - '0';
	if(curSum >= n){
		cout << 0 << endl;

	}
	else{
		multiset<int, greater<int> > q;
		for(int i = 0; i < sz(s); ++i){
			int c = s[i] - '0';
			q.insert(9-c);
		}
		int needToIncrease = n - curSum;
		int resp = 0;
		while(needToIncrease > 0){
			int start = *(q.begin());
			needToIncrease -= start;
			resp++;
			q.erase(q.begin());
		}
		cout << resp << endl;
	}
}

