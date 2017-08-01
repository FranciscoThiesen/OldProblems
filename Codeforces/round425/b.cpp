/*input
abc
a?a?a*
4
abacaba
abaca
apapa
aaaaax
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);
#define sz(v) (v).size()

#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int Inf = 0x3F3F3F3F;
const int negInf = 0xC0C0C0C0;
const ll mod = 1e9 + 7;

string pat;
vector<int> good(26, false);

bool solve(string& s){
	if(pat.size() -1 > s.size()) return false;
	string k = pat;
	bool can = true;
	int flag = -1;
	int idx = (int)s.size()-1;
	int tam = (int)k.size() -1;
	for(int i = 0; i < k.size(); ++i){
		if(k[i] == '*')
		{
			flag = i;
			break;
		}
		if(k[i] == '?')
		{
			if(good[s[i] - 'a'])
			{
				k[i] = s[i];
			}
			else
			{
				return false;
			}
		}
	}
	if(flag != -1)
	{
		
		for(int i = tam; i >= flag; --i){
			if(idx < 0) break;
			if(k[i] == '?')
			{
				if(good[s[idx] - 'a'])
				{
					k[i] = s[idx];
				}
				else
					return false;
			}
			idx--;
		}
	}
	else return k == s;
	string prev;
	string pos;
	string cur;
	for(int i = 0; i <= tam; ++i){
		if(k[i] == '*'){
			prev = cur;
			cur.clear();
		}
		else cur += k[i];
	}
	pos = cur;
	string replace = "";
	bool c3 = true;
	string wrd = prev + replace + pos;
	int sizeDiff = (int)s.size() - (int)k.size();
	if(sizeDiff == -1){
		return wrd == s;
	}
	for(int i = flag; i <= flag + sizeDiff; ++i){ // trying to replace part of the string
		if(good[s[i]- 'a']){
			return false;
		}
		replace += s[i];
	}
	wrd = prev + replace + pos;
	return wrd == s;
}
int main()
{
	string g;
	cin >> g;
	cin >> pat;
	string t = pat;
	for(char c : g) good[c -'a'] = true;
	int q;
	cin >> q;
	string tmp;
	int tam = (int)pat.size();
	while(q--){
		cin >> tmp;
		if(solve(tmp)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
