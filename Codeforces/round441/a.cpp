/*input
1
2
3
5
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
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int eat = 1;
	int dist = 0;
	int cur = 0;
	while(eat < n){
		if(cur == 0){
			if(a < b){
				dist += a;
				cur = 1;
				eat++;
			}else{
				dist += b;
				cur = 2;
				eat++;
			}
		}
		else if(cur == 1){
			if(a < c){
				cur = 0;
				dist += a;
				eat++;
			}
			else{
				dist += c;
				cur = 2;
				eat++;
			}
		}
		else{
			if(b < c){
				dist += b;
				eat++;
				cur = 0;
			}
			else{
				dist += c;
				eat++;
				cur = 1;
			}
		}
	}
	cout << dist << endl;
	return 0;
}

