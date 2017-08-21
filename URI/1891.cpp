#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define ins insert
#define pb push_back
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)

int t, n, d, k;
char c;

int valid(int i){
	return (i >= 0 && i < n);
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		vector<bool> active(n, true);
		string state = "";
		vector<int> ans;
		set<int> Ds;
		rp(i, n){
			cin >> c;
			if(c == 'D'){
				Ds.insert(i);
			}
			state += c;
		}

		while(!Ds.empty()){
			d = *(Ds.begin());
			Ds.erase(Ds.begin());
			ans.pb(d);
			active[d] = false;
			int i = d;
			if(valid(i-1)){
				if(active[i-1]){
					if(state[i-1] == 'D'){
						state[i-1] = 'B';
						Ds.erase(Ds.find(i-1));
					}
					else{ Ds.insert(i-1); state[i-1] = 'D';}
				}
			}
			if(valid(i+1)){
				if(active[i+1]){
					if(state[i+1] == 'D'){
						state[i+1] = 'B';
						Ds.erase(Ds.find(i+1));
					}
					else{ Ds.insert(i+1);state[i+1] = 'D';}
				}
			}
		}
		if((int)ans.size() == n){
			cout << "Y" << endl;
			rp(i, n){
				if(i == n-1)
					cout << ans[i] + 1 << endl;
				else
					cout << ans[i] + 1 << " ";
			}
		}
		else cout << "N" << endl;
	}
	return 0;
}
