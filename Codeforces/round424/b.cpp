/*input
qwertyuiopasdfghjklzxcvbnm
veamhjsgqocnrbfxdtwkylupzi
TwccpQZAvb2017
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define gcd __gcd
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;

map<char, char> conv;

int main()
{
	string a1, a2, r;
	cin >> a1 >> a2;
	for(int i = 0; i < 26; ++i){
		conv[a1[i]] = a2[i];
	}
	cin >> r;
	string resp;
	for(char c : r)
	{
		if(!isalpha(c)){
			resp += c;
			continue;
		}
		bool upper = isupper(c);
		if(upper) c = tolower(c);
		char o = conv[c];
		if(upper) resp += toupper(o);
		else resp += o;

	}
	cout << resp << endl;
	return 0;
}
