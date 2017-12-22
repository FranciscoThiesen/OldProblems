/*input
5
01
10
101
11111
0
3
1 2
6 5
4 4
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
#define IOS ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int d = 2;
// suppose max K is 10
vector<vector<string> > comb(11, vector<string>(0));

void genComb(int k){
	if(k == 1){
		string q ("1");
		string q2 ("0");
		comb[k].pb(q);
		comb[k].pb(q2);
	}
	else{
		int t = 1 << (k-1);
		for(int i = 0; i < t; ++i){
			comb[k].pb(comb[k-1][i] + '0');
			comb[k].pb(comb[k-1][i] + '1');
		}
	}
}

bool search(string& pat, string& txt, int q)
{
    int M = (int)pat.size();
    int N = (int)txt.size();
    if(M > N) return false;
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( p == t )
        {
            // /* Check for characters one by one */
            // for (j = 0; j < M; j++)
            // {
            //     if (txt[i+j] != pat[j])
            //         break;
            // }
 
            // // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            // if (j == M)
            return true;
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
 
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
        }
    }
    return false;
}

bool f(string& s, int k){
	int t = 1 << k;
	for(int i = 0; i < t; ++i){
		if(!search(comb[k][i], s, 35317))
		{
			return false;
		}
	}
	return true;
}

int solve(string& s){
	int lo = 0, hi = 10, mid;
	while(lo < hi){
		mid = (hi + lo + 1)/2;
		if(f(s,mid)){
			lo = mid;
		}else{ hi = mid-1;}
	}
	return lo;
}

int main(){
	int n;
	IOS
	cin >> n;
	vector<string> s(n);
	rp(i, n) cin >> s[i];
	fr(i, 1, 11) genComb(i);
	int op;
	cin >> op;
	rp(i, op){
		int a, b;
		cin >> a >> b;
		--a;--b;
		string nova = s[a] + s[b];
		cout << solve(nova) << endl;
		s.pb(nova);
	}
	return 0;
}

