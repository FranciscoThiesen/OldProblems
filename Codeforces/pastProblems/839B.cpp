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

const int maxn = 101;
int arr[maxn];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int g4 = n;
	int g2 = 2*n;
	int g1 = 0;
	rp(i, k) scanf("%d", &arr[i]);
	sort(arr, arr+k, greater<int>());
	rp(i, k){
		int v = arr[i];
		while(v > 0){
			if(v > 2){
				if(g4){
					g4--;
					v -= 4;
				}
				else if(g2){
					g2--;
					v -= 2;
				}
				else{
					puts("NO");
					return 0;
				}
			}
			else if(v == 2){
				if(g2){
					g2--;
					v -= 2;
				}
				else if(g4){
					g4--;
					v -= 2;
					g1++;
				}
				else if(g1 >= 2){
					g1 -= 2;
					v -= 2;
				}
				else{
					puts("NO");
					return 0;
				}
			}
			else{
				if(g1){
					g1--;
					v--;
				}
				else if(g2){
					g2--;
					v--;
				}
				else if(g4){
					g4--;
					g2++;
					v--;
				}
				else{
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	return 0;
}

