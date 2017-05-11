#include <bits/stdc++.h>

#define endl '\n'
#define MAXN 400
using namespace std;

int main()
{
	int t;
	cin >> t;
	int mat[MAXN][MAXN] = {{0}};
	while(t--)
	{
		int k;
		cin >> k;
		if(k == 1)
		{	
			cout << 1 << endl;
			continue;
		}
		memset(mat, 0, sizeof(mat));
		// filling the main diagonal with x
		for(int x = 0; x < k; ++x)
			mat[x][x] = k;
		
		vector<int> diag(k*2 - 1, 0);
		diag[k-1] = k;// fixando a diagonal principal


		//now i have to place half of the ones in the lowest posible diagonal
		// i'll place floor(k/2) 1's on the lower diagonal
		int lowDiagY = k - ( (int) ceil(k/2.0));
		diag[k-1 + lowDiagY] = 1;
		int diff = k - 1 + lowDiagY;
		int lowDiagX = 0;
		
		for(int i = 0; i <= k -((int)ceil(k/2.0)); ++i) 
		{
			if(lowDiagX >= k || lowDiagY >= k)
				break;
			mat[lowDiagX][lowDiagY] = 1;
			lowDiagX++;
			lowDiagY++;
		}
		//now i have to place half - 1 of the ones in the highest posible diagonal
		int highDiagY = 0;
		int highDiagX = k - ( (int) floor(k/2.0));
		diag[k-1 - highDiagX] = 1;
		diff -= k-1-highDiagX;
		for(int i = 0; i < k - ((int) floor(k/2.0)); ++i)
		{
			if(highDiagX >= k || highDiagY >= k)
				break;
			mat[highDiagX][highDiagY] = 1;
			highDiagY++;
			highDiagX++;	
		}
		set<int> missin;
		for(int i = 2; i < k; ++i)
			missin.insert(i);
		
		for(auto& q : missin)
		{
			for(int p = 0; p < k-1; ++p)
			{
				if(diag[p] == 0 && diag[p+diff] == 0)
				{
					diag[p] = q;
					diag[p+diff] = q;
					break;
				}
			}
		}

		// diagonais estao colocadas corretamente, falta agora preencher a matriz
		for(int i = 0; i < k-1; ++i)
		{
			//preenchendo as diagonais superiores
			int begX = k-i-1;
			int begY = 0;
			while(begX < k)
			{
				mat[begX][begY] = diag[i];
				begX++;
				begY++;
			}
		}
		for(int i = k; i < diag.size(); ++i)
		{
			//preenchendo as diagonais superiores
			int begY =i-k+1;
			int begX = 0;
			while(begY < k)
			{
				mat[begX][begY] = diag[i];
				begX++;
				begY++;
			}
		}

		for(int y = 0; y < k; ++y)
		{
			for(int x = 0; x < k; ++x)
			{
				cout << mat[x][y] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
