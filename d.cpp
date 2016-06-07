#include <stdio.h>
#include <algorithm>

using namespace std;

int matrix[5010][30];

int dp(int info[][30], int p, int f, int custo)
{
	matrix[0][0] = info[0][0];
	for (int i = 1; i < f; ++i)
	{
		matrix[0][i] = info[0][i]+custo;
	}
	for (int i = 1; i < p; ++i)
	{
		int menor = matrix[i-1][0];
		for (int k = 1; k < f; ++k)
		{
			if(matrix[i-1][k]<menor)
			{
				menor = matrix[i-1][k];
			}
		}

		for (int j = 0; j < f; ++j)
		{
			matrix[i][j] = min(menor+custo+info[i][j], info[i][j]+matrix[i-1][j]);
		}
	}

	int menor = matrix[p-1][0];
	for (int k = 1; k < f; ++k)
	{
		if(matrix[p-1][k]<menor)
		{
			menor = matrix[p-1][k];
		}
	}
	return menor;
}

int main()
{
	int F,P,E,A, info[5010][30];
	while(scanf("%d %d %d %d", &F, &P, &E, &A), F!=0 && P!=0 && E!=0 && A!=0)
	{
		int custoT = E*A;
		for(int i=0; i<P; i++)
		{
			for (int j = 0; j < F; ++j)
			{
				int a,b;
				scanf("%d %d", &a, &b);
				info[i][j] = a*b;
			}
		}
		printf("%d\n", dp(info, P, F, custoT));

	}

}