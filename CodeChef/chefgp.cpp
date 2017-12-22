/*input
6
ab
1 1
aab
1 1
aabb
1 2
aaaaab
2 1
aaaa
1 3
aaaaa
2 2
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

void solve(int qntA, int qntB, int cA, int cB){
	int sm = min(qntA, qntB);
	int missing, coloca;
	if(sm == qntA && sm == qntB){
		rp(i, qntA + qntB){
			if(i%2) cout << "a";	
			else cout << "b";
		} return ;
	}
	int flag = -1;
	vector<ii> interv(2*sm + 1, {1,0});
	if(sm == qntA){ // even position -> cB	
		flag = 1;
		missing = qntB - (sm+1);
		coloca = cB - (interv[0].fi % cB);
		while(missing){
			coloca = cB - (interv[0].fi % cB);
			rp(i, 2*sm + 1){
				if(i%2 == 0){
					coloca = min(coloca, missing);
					interv[i].fi += coloca;
					missing -= coloca;
				}
				if(!missing) break;
			}
		}
	}
	else{ // even position -> cA
		flag = 0;
		missing = qntA - (sm+1);
		while(missing){
			coloca = cA - (interv[0].fi % cA);
			rp(i, 2*sm+1){
				if(i%2 == 0){
					coloca = min(coloca, missing);
					interv[i].fi += coloca;
					missing -= coloca;
				}
				if(!missing)break;
			}
		}
	}
	if(flag){
		int rep = 0;
		fr(j, 0, 2*sm + 1){
			if(j%2 == 0){
				rp(i, interv[j].fi){
					if(rep == cB){
						cout << "*";
						rep = 0;
					}
					cout << "b";
					rep++;
				}
			}
			else{
				cout << "a";
				rep  = 0;
			}
		}
	}
	else{
		int rep = 0;
		fr(j, 0, 2*sm + 1){
			if(j%2 == 0){
				rp(i, interv[j].fi){
					if(rep == cA){
						cout << "*";
						rep = 0;
					}	
					cout << "a";
					rep++;
				}
			}
			else{
				cout << "b";
				rep = 0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int qA = 0, qB = 0, cA, cB;
		for(const char& c : s){
			if(c == 'a')qA++;
			else qB++;
		}
		cin >> cA >> cB;
		solve(qA, qB, cA, cB);
		cout << endl;
	}
	return 0;
}

