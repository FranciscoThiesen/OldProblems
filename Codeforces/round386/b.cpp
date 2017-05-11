/*input
1
a
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string dec;
	cin >> dec;
	if(n%2 == 1)
	{
		string tmp;
		tmp += dec[0];
		for(int i = 1; i < n; ++i)
		{
			if(i%2 == 0)
				tmp += dec[i];
			else
			{
				string aux;
				aux += dec[i];
				aux += tmp;
				tmp = aux;
			}
		}
		cout << tmp;
	}
	else
	{
		string tmp;
		tmp += dec[0];
		for(int i = 1; i < n; ++i)
		{
			if(i%2 == 1)
				tmp += dec[i];
			else
			{
				string aux;
				aux += dec[i];
				aux += tmp;
				tmp = aux;
			}
		}
		cout << tmp;
	}
	
	return 0;
}