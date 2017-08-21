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
const int maxn = 1001;

char mat[maxn][maxn];
int minSal[maxn], rem[maxn], offer[maxn], hired[maxn];
int t, n, m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;	
	while(t--){
		cin >> n >> m;
		int contratado = 0;
		memset(minSal, 0, sizeof minSal);
		memset(rem, 0, sizeof rem);
		memset(offer, 0, sizeof offer);
		memset(hired, 0, sizeof hired);
		ll salSum = 0;
		rp(i, n) cin >> minSal[i];
		rp(i, m) cin >> offer[i] >> rem[i]; 
		rp(i, n){
			rp(j, m){
				cin >> mat[i][j];
			}
		}
		rp(i, n){
			int bestSal = 0;
			int company = -1;
			rp(j, m){
				if(mat[i][j] == '1'){
					if(hired[j] < rem[j] && offer[j] > minSal[i] && offer[j] > bestSal){
						bestSal = offer[j];
						company = j;
					}	
				}
			}
			if(company >= 0){
				hired[company]++;
				salSum += bestSal;
				contratado++;
			}
		}
		int zerado = 0;
		rp(i, m) if(hired[i] == 0) zerado++;
		cout << contratado << " " << salSum << " " << zerado << endl;
	}
	return 0;
}

