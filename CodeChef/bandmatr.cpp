// https://www.codechef.com/MARCH17/problems/BANDMATR
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define mp make_pair
#define fi first
#define fr(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define fu(i, a) fr(i,0,a)
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
constexpr int MAXN = 501;
 
int mat[MAXN][MAXN] = {{0}};
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int x = t;
	while(t--)
	{
		int n;
		cin >> n;
		//cout << "pru" << endl;
		vi zero(n, 0);
		int remZero = 0;
		fu(l, n)
		{
			fu(c, n)
			{
				cin >> mat[l][c];
				if(!mat[l][c])zero[abs(l-c)]++, remZero++;
		//		cout << mat[l][c] << " ";
			}
		//	cout << endl;
		}
 
		vi accu(n, 0);//number of zeros on lower levels (exclusive)
		accu[0] = 0;
		fr(i, 1, n)
		{
			accu[i] = accu[i-1] + zero[i-1]; 
		}
 
		vector<int> accuRev(n, 0);//number of zeros on higher levels (inclusive)
		accuRev[n-1] = zero[n-1];
		//cout << accuRev[n-1] << " " << zero[n-1] << endl;
 
		for(int i = n-2; i >= 0; --i)
			accuRev[i] = accuRev[i+1] + zero[i];
 
		int k = n-1;//guaranteed
		int needZero = 0;
		int totZero = 0;
		for(int i = n-1; i > 0; --i)
		{
			//needZero -> total number of zeros needed on leves i, i+1, ..., n-1
			if(i == 0)needZero += n;
			else needZero += 2*(n-i);
			//cout << "nivel = " << n-1 << endl;
			//cout <<  accu[i] << " " <<  accuRev[i]  << " " << accu[i] + accuRev[i] << " >= " << needZero << " ? " << endl;
			if(accu[i] + accuRev[i] >= needZero) k = i-1;
			else break;
		}
		cout << k << endl;
	}
	return 0;
} 