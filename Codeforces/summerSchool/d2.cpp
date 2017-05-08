#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define MAXN 100002
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef vector<ll> vll;
typedef vector<ull> vull;

char totS[MAXN];
int p[2*MAXN];

void manacher()
{
	int m = 0;
	char t[MAXN*2];
	for(int i = 0; totS[i]; ++i)
	{
		t[m++] = '#';
		t[m++] = totS[i];
		p[i] = 0;
	}
	t[m++] = '#';
	int c = 0, r = 0;
	for(int i = 0; i < m; ++i)
	{

		int i_ = 2*c - i;
		p[i] = r > i ? min(r-i, p[i_]) : i & i;
		while(0 <= i - p[i]-1 && i +p[i]+ 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1])
			p[i] += 2;
		if(i + p[i] > r)
		{
			c=  i;
			r = i + p[i];
		}
	}
}

vi z_algo(string &str)
{
	int n = str.size();
	vi Z(n,0);
	for(int i = 1, l = 0, r = 0; i <n ;++i)
	{
		if(i <= r)
			Z[i] = min(r-i + 1, Z[i-1]);
		while(i + Z[i] < n && str[Z[i]] == str[i + Z[i]])
			++Z[i];
		if(Z[i] > r - i + 1)
			l = i, r = i + Z[i] -1;
	}
	return Z;
}

int main()
{
	
	string s1, s2, tot;
	cin >> s1 >> s2;

	if(s1.size() != s2.size())
	{
		cout << "No" << endl;
		return 0;
	}

	tot += s2;
	tot += '#';
	tot += s1;
	for(int i = 0; i < tot.size(); ++i)
		totS[i] = tot[i];
	manacher();

	vi zVec = z_algo(tot);

	int tamPalMeio = p[tot.size()]/2;
	int maxVal = -1;
	int idx;
	for(int i = 0; i < zVec.size(); i++)
	{
		if(zVec[i] > maxVal)
		{
			maxVal = zVec[i];
			idx = i;
		}
	}
	
	int beg = s1.size()+1;
	//int ans = s1.size() - pos;
	int ans = numeric_limits<int>::max();
 
	int falta = tot.size() - idx;//incluindo o elemento, quantos caras tem a minha direita
	if(zVec[idx] == falta)
	{
		//temos que fazer o match da parte a esquerda dele, com a parte final a string 1
		int faltamEsquerda = idx - beg;
		if(tamPalMeio >= faltamEsquerda)
		{
			ans = min(ans, faltamEsquerda);
		}
	}
/*for(int i = 0, j = ans; i < pos; i++, j++)
	{
		if(s1[j] != s2[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}

	reverse(s1.begin(), s1.end());

	for(int i = pos; i < s1.size(); i++)
	{
		if(s1[i] != s2[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}*/
	if(ans == numeric_limits<int>::max())
		cout << "No" << endl;
	else
	{	
		cout << "Yes" << endl;
		cout << ans << endl;
	}



}