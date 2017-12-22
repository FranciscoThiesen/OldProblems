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

set<string> g;

int main(){
	int n;
	cin >> n;
	vector<string> vec(n);
	rp(i, n){
		cin >> vec[i];
		rp(st, 9){
			string tmp;			
			tmp += vec[i][st];
			g.insert(tmp);
			fr(nxt, st, 10){
				tmp += vec[i][nxt];
				g.insert(tmp);
			}
		}
	}
	rp(i, n){
		bool flag = false;
		fr(sz, 1, 10){
			rp(st, 10-sz){
				cout << "vamos ver a substr (" << st << "," << st+sz-1 <<")" << endl;
				string s;
				fr(k, st, st+sz){
					s += vec[i][k];
				}
				cout << s << endl;
				if(g.find(s) == g.end()){
					cout << s << endl;
					flag = true;
					break;
				}
			}
			if(flag) break;
		}

	}
	return 0;
}

