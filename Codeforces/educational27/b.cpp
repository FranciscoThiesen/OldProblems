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

bool cmp(const int& a, const int& b){
	return abs(a) < abs(b);
}

int doit(string& s1, string& s2){
	int sumA = 0;
	int sumB = 0;
	for(char c : s1) sumA += c - '0';
	for(char c : s2) sumB += c - '0';
	if(sumA < sumB){
		swap(s1, s2);
		swap(sumA, sumB);
	}
	int need = sumA - sumB;
	vi can;
	for(char c : s2) can.pb(9 - (c - '0'));
	for(char c : s1) can.pb(c-'0');
	int resp = 0;
	sort(all(can));
	while(need){
		int lst = can.back();
		if(lst >= need){
			return resp + 1;
		}
		else{
			resp++;
			need -= lst;
			can.pop_back();
		}
	}
	return resp;
}

int main(){
	string s;
	cin >> s;
	string fst, snd;
	rp(i, 6){
		if(i < 3) fst += s[i];
		else snd += s[i];
	}
	cout << doit(fst, snd) << endl;
	return 0;
}
