/*input
2 3
BBW
WWW
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

const int maxn = 101;

int l, r;

char mat[maxn][maxn];

bool valid(int i, int j)
{
	return (i >= 0 && i < l && j >= 0 && j < r);
}
int main()
{
	int countB = 0;
	int highB = inf;
	int lowB = -1;
	int leftB = inf;
	int rightB = -1;
	int resp = inf;

	cin >> l >> r;
	for(int i = 0; i < l; ++i){
		for(int j = 0; j < r; ++j){
			cin >> mat[i][j];
			if(mat[i][j] == 'B'){
				countB++;
				highB = min(highB, i);
				lowB = max(lowB, i);
				leftB = min(j, leftB);
				rightB = max(rightB, j);
			}
		}
	}

	if(countB == 0){
		cout << 1 << endl;
		return 0;
	}
	if(countB == 1){
		cout << 0 << endl;
		return 0;
	}
	int side = max(lowB - highB + 1, rightB - leftB + 1);
	bool ok = false;

	if(side == lowB - highB + 1){
		for(int leftStart = rightB - side + 1; leftStart <= leftB; ++leftStart)
		{
			bool tmp = true;
			int cnt = 0;
			for(int i = highB; i <= lowB; ++i)
			{
				for(int j = leftStart; j < leftStart + side; ++j)
				{
					if(!valid(i, j))
					{
						tmp = false;
						goto NXT;
					}
					else if(mat[i][j] == 'W')cnt++;
				}
			}
NXT:
			if(tmp)
			{
				ok =true;
				resp = min(resp,cnt);
			}
		}
	}
	else if(side == rightB - leftB + 1){
		for(int upStart = lowB - side + 1; upStart <= highB ; ++upStart)
		{
			bool tmp2 = true;
			int cnt2 = 0;
			for(int i = upStart; i < upStart + side; ++i)
			{
				for(int j = leftB; j <= rightB; ++j)
				{
					if(!valid(i, j))
					{
						tmp2 = false;
						goto NXT2;
					}
					else if(mat[i][j] == 'W')
					{
						cnt2++;
					}
				}
			}
NXT2:
			if(tmp2)
			{
				ok =true;
				resp = min(resp, cnt2);
			}
		}
	}
	if(ok) cout << resp << endl;
	else cout << -1 << endl;
}