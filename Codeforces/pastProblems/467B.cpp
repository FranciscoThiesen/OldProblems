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

double total = 0;
double ok = 0;
int need = 0;

void compute(int n, int rem){
	if(rem == 0){
		total++;
		ok += (n == need)? 1 : 0;
	}
	else{
		compute(n+1, rem-1);
		compute(n-1, rem-1);
	}
}


main(){
	string s1, s2;
	cin >> s1 >> s2;
	for(const char& c : s1) need += (c == '+')? 1 : -1;
	int pts = 0;
	int indef = 0;
	for(const char& c : s2){
		if(c == '?') indef++;
		else if(c == '+')pts++;
		else pts--;
	}
	if(indef == 0){
		if(pts == need){
			printf("1.0000000000\n");
		}
		else printf("0.0000000000\n");
	}
	else{
		compute(pts, indef);
		printf("%.10f\n", ok / total);
	}
}
