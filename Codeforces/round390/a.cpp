/*input
....
x...
....
..x.
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

int main()
{	
	char mat[4][4];
	for(int y = 0; y < 4; ++y)
	{
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); ++i)
		{
			mat[y][i] = s[i];
		}
	}
	//checando todas as linhas horizontais
	for(int y = 0; y < 4; ++y)
	{
		for(int x = 0; x < 2; ++x)
		{
			if(mat[y][x] == 'x' && mat[y][x+1] == '.' && mat[y][x+2] == 'x')
			{
				cout << "YES" << endl;
				return 0;
			}
			if(mat[y][x] == 'x' && mat[y][x+1] == 'x' && mat[y][x+2] == '.')
			{
				cout << "YES" << endl;
				return 0;
			}
			if(mat[y][x] == '.' && mat[y][x+1] == 'x' && mat[y][x+2] == 'x')
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	//checando verticais
	for(int x = 0; x < 4; ++x)
	{
		for(int y = 0; y < 2; ++y)
		{
			if(mat[y][x] == 'x' && mat[y+1][x] == '.' && mat[y+2][x] == 'x')
			{
				cout << "YES" << endl;
				return 0;
			}
			if(mat[y][x] == '.' && mat[y+1][x] == 'x' && mat[y+2][x] == 'x')
			{
				cout << "YES" << endl;
				return 0;
			}
			if(mat[y][x] == 'x' && mat[y+1][x] == 'x' && mat[y+2][x] == '.')
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	// checando diagonais 
	for(int x = 0; x < 2; ++x)
	{
		//principal
		if(mat[x][x] == 'x' && mat[x+1][x+1] == 'x' && mat[x+2][x+2] == '.')
		{
			cout << "YES" << endl;
			return 0;
		}
		if(mat[x][x] == '.' && mat[x+1][x+1] == 'x' && mat[x+2][x+2] == 'x')
		{
			cout << "YES" << endl;
			return 0;
		}
		if(mat[x][x] == 'x' && mat[x+1][x+1] == '.' && mat[x+2][x+2] == 'x')
		{
			cout << "YES" << endl;
			return 0;
		}
	}


	//checando diag normal
	if(mat[1][0] == 'x' && mat[2][1] == 'x' && mat[3][2] == '.')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[1][0] == '.' && mat[2][1] == 'x' && mat[3][2] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[1][0] == 'x' && mat[2][1] == '.' && mat[3][2] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}


	if(mat[0][1] == 'x' && mat[1][2] == 'x' && mat[2][3] == '.')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[0][1] == '.' && mat[1][2] == 'x' && mat[2][3] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[0][1] == 'x' && mat[1][2] == '.' && mat[2][3] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}

	//checando diagonal contraria
	if(mat[3][0] == 'x' && mat[2][1] == 'x' && mat[1][2] == '.')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[3][0] == 'x' && mat[2][1] == '.' && mat[1][2] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[3][0] == '.' && mat[2][1] == 'x' && mat[1][2] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}



	//checando diag contraria
	if(mat[2][1] == '.' && mat[1][2] == 'x' && mat[0][3] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[2][1] == 'x' && mat[1][2] == '.' && mat[0][3] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[2][1] == 'x' && mat[1][2] == 'x' && mat[0][3] == '.')
	{
		cout << "YES" << endl;
		return 0;
	}

	//checando diag menores
	if(mat[2][0] == '.' && mat[1][1] == 'x' && mat[0][2] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[2][0] == 'x' && mat[1][1] == '.' && mat[0][2] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[2][0] == 'x' && mat[1][1] == 'x' && mat[0][2] == '.')
	{
		cout << "YES" << endl;
		return 0;
	}


	if(mat[3][1] == '.' && mat[2][2] == 'x' && mat[1][3] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[3][1] == 'x' && mat[2][2] == 'x' && mat[1][3] == '.')
	{
		cout << "YES" << endl;
		return 0;
	}
	if(mat[3][1] == 'x' && mat[2][2] == '.' && mat[1][3] == 'x')
	{
		cout << "YES" << endl;
		return 0;
	}


	cout << "NO" << endl;
	return 0;
}