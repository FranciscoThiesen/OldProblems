/*input
asdfasdf
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
set<char> vow;

string solve(string& s){
	vector<pair<int, string> > invalidBlocks;
	if(sz(s) < 3) return s;
	string resp;
	char p1 = s[0];
	char p2 = s[1];
	resp += p1;
	resp += p2;
	int tam = sz(s);
	for(int i = 2; i < tam; ++i){
		if(vow.find(s[i]) == vow.end()){
			bool is1 = (vow.find(p1) == vow.end());
			bool is2 = (vow.find(p2) == vow.end());
			if(is1 && is2){
				if(s[i] == p1 && s[i] == p2){
					resp += s[i];
					continue;
				}
				else{
					resp += ' ';
					resp += s[i];
					p1 = 'a';
					p2 = s[i];
				}
			}
			else{
				p1 = p2;
				p2 = s[i];
				resp += s[i];
			}
		}
		else{
			resp += s[i];
			p1 = p2;
			p2 = s[i];
		}
	}
	return resp;
	
}

int main(){
	string s;
	cin >> s;	
	vow.insert('a');
	vow.insert('e');
	vow.insert('i');
	vow.insert('o');
	vow.insert('u');
	cout << solve(s) << endl;

	return 0;
}

