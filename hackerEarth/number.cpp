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

int t;
string s;

int best(){
	int countR = 0;
	for(char &c : s) countR += (c == 'R');
	int tam = sz(s);
	vi freq;
	char prev = s[0];
	int curSz = 1;
	fr(i, 1, tam){
		if(s[i] == prev)curSz++;
		else{
			if(prev == 'R'){ freq.pb(-curSz);prev = 'K';}
			else{freq.pb(curSz); prev = 'R';}
			curSz = 1;
		}
	}
	if(prev == 'R')freq.pb(-curSz);
	else freq.pb(curSz);
	int b = 0;
	int cur = 0;
	for(const int& v : freq){
		cur += v;
		b = max(b, cur);
		cur = max(0, cur);
	}
	if(b == 0) return countR - 1;
	return countR + b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> s;
		cout << best() << endl;
	}
	return 0;
}

