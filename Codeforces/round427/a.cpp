/*input
4 5 3 1 5
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

main(){
	int s, v1, t1, v2, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int time1 = s*v1+2*t1;
	int time2 = s*v2+2*t2;
	if(time1 == time2){
		cout << "Friendship" << endl;
	}
	else if(time1 > time2)
		cout << "Second" << endl;
	else cout << "First" << endl;
}

