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

bool win(string& a, string& b){
	vi freqA(26, 0), freqB(26, 0);
	for(char c : a) freqA[c-'a']++;
	for(char c : b) freqB[c-'a']++;
	rp(i, 26){
		if(freqA[i] >= 2 && freqB[i] == 0){
			return true;
		}
	}
	bool aCb = true;
	rp(i, 26){
		if(freqB[i] && !freqA[i]){
			aCb = false;
		}
	}
	if(aCb){
		rp(i, 26){
			if(freqA[i] && !freqB[i]){
				return true;
			}
		}	
	}
	return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		if(win(a,b)) cout << "A" << endl;
		else cout << "B" << endl;
	}
	return 0;
}

