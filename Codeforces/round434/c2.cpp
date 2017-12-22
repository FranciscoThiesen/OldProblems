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
	string s;
	cin >> s;
	int countRep = 1;
	int t = sz(s);
	rp(i, t){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			cout << s[i];
			countRep = 1;
		}
		else{
			if(countRep >= 3){
				if(s[i] == s[i-1] && s[i] == s[i-2]){
					countRep++;
					cout << s[i];
				}
				else{
					countRep = 2;
					cout << " ";
					cout << s[i];
				}
			}
			else{
				countRep++;
				cout << s[i];
			}
		}
	}
	return 0;
}

