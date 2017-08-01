// https://www.codechef.com/JAN17/problems/RESERVOI
#include <bits/stdc++.h>
 
using namespace std;
 
char mat[1001][1001];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int lin, col;
		cin >> lin >> col;
		for(int l = 0; l < lin; ++l)
			for(int c = 0; c < col; ++c)
				cin >> mat[l][c];
		bool stable = true;
		for(int l = 0; l < lin; ++l)
		{
			for(int c = 0; c < col; ++c)
			{
				if(l == lin-1 && mat[l][c] == 'W')
				{
					stable = false;
					goto end;
				}
				if(c == 0 || c == col-1)
				{
					if(mat[l][c] == 'W')
					{
						stable = false;
						goto end;
					}
					if(mat[l][c] == 'A')
					{
						if(l != 0)
						{
							if(mat[l-1][c] != 'A')
							{
								stable = false;
								goto end;
							}
						}
					}
					if(mat[l][c] == 'B')
					{
						if(l+1 < lin)
						{
							if(mat[l+1][c] == 'A')
							{
								stable = false;
								goto end;
							}
						}
					}
				}
				else
				{
					if(mat[l][c] == 'A')
					{
						if(l != 0)
						{
							if(mat[l-1][c] != 'A')
							{
								stable = false;
								goto end;
							}
						}
					}
					else if(mat[l][c] == 'W')
					{
						if(mat[l][c-1] == 'A')
						{
							stable = false;
							goto end;
						}
						if(l+1 < lin)
						{
							if(mat[l+1][c] == 'A')
							{
								stable = false;
								goto end;
							}
						}
						if(mat[l][c+1] == 'A')
						{
							stable = false;
							goto end;
						}
					}
				}
			}
		}
		end:
			if(stable)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
	}
	return 0;
 
} 