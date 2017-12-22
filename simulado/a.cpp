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

bool checkDec(vector<int>& v){
	int prev = 1e9;
	int prev2 = 1e9;
	int n = (int)v.size();
	int del = 0;
	fr(i, 0, n){
		if(v[i] > prev){
			if(del == 1) return false;
			del++;
			if(v[i] <= prev2){
				prev = v[i];
			}
		}
		else{
			prev2 = prev;
			prev = v[i];
		}
	}
	return true;
}

bool checkInc(vector<int>& v){
	int prev = -1;
	int prev2 = -1;
	int del = 0;
	int n = (int) v.size();
	fr(i,0,n){
		if(v[i] < prev){
			if(del == 1) return false;
			del++;
			if(v[i] >= prev2){
				prev = v[i];
			}
		}
		else{
			prev2 = prev;
			prev = v[i];
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		vector<int> arr(n);
		rp(i, n) scanf("%d", &arr[i]);
		if(checkInc(arr) || checkDec(arr)){
			puts("YES");
		}else puts("NO");
	}
	return 0;
}

