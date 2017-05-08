#include <bits/stdc++.h>

// TODO - Observar o caso 2 do URI e pensar em como tratar
using namespace std;

int main()
{
	int n, p, x, y;
	int mat[500][500] = {{0}};
	scanf("%d %d", &n, &p);
	int pretas = p;
	int brancas = p;
	for(int i = 0; i < p; ++i)
	{
		scanf("%d %d", &y, &x);
		mat[x-1][y-1] = 1;//marcando pretas
	}
	for(int i = 0; i < p; ++i)
	{
		scanf("%d %d", &y, &x);
		mat[x-1][y-1] = 2;//marcando brancas
	}
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			printf("%d ", mat[x][y]);
		}
		printf("\n");
	}
	vector<int> accu(n, 0);
	for(int colunaInicial = 0; colunaInicial < n; ++colunaInicial)
	{
		//inicializando os valores de acumula
		for(int k = 0; k < n; ++k)
			accu[k] = mat[colunaInicial][k];

		//acumulando os valores das proximas colunas
		for(int proximaColuna = colunaInicial + 1; proximaColuna < n; ++proximaColuna)
		{
			for(int y = 0; y < n; ++y)
			{
				if(accu[y] == 1)
				{
					if(mat[proximaColuna][y] == 2)
					{
						accu[y] = -1;
					}
				}
				else if(accu[y] == 2)
				{
					if(mat[proximaColuna][y] == 1)
					{
						accu[y] = -1;
					}
				}
				else if(accu[y] == 0)
					accu[y] = mat[proximaColuna][y];
			}

			int quadDim = proximaColuna - colunaInicial + 1;//tamanho do quadrado KxK que estamos buscando nessa query
			int sz = 0;
			int color = 0;
			//percorrendo accu para achar uma sequencia valida de 1 ou 2, de tamanho quadDim

			for(int k = 0; k < n; ++k)
			{
				if(accu[k] == -1)
				{
					color = 0;
					sz = 0;
				}
				else if(accu[k] == 0)
				{
					sz++;
				}
				else if(accu[k] == 1)
				{
					if(color == 1)
					{
						sz++;
					}
					else if(color == 0)
					{
						color = 1;
						sz++;
					}
					else
					{
						color = 1;
						sz=1;
					}
				}
				else if(accu[k] == 2)
				{
					if(color == 1)
					{
						color = 2;
						sz = 1;
					}
					else if(color == 0)
					{
						sz++;
						color = 2;
					}
					else
					{
						sz++;
					}
				}
				if(sz >= quadDim && color != 0)
				{
					if(color == 1)
					{
						printf("Pretas aumentou 1\n");
						printf("Coluna inicial = %d e coluna final = %d ... o quadrado possui tamanho %dx%d\n\n", colunaInicial, proximaColuna, quadDim, quadDim);
					}
					else if(color == 2)
					{

						printf("Brancas aumentou 1\n");
						printf("Coluna inicial = %d e coluna final = %d ... o quadrado possui tamanho %dx%d\n\n", colunaInicial, proximaColuna, quadDim, quadDim);
					}
					//for(auto& p : accu)
					//	cout << p << "   <-" << endl;
					if(color == 1)
						pretas++;
					else if(color == 2)
						brancas++;
				}
			}
		}
	}
	printf("%d %d\n", pretas, brancas);
	return 0;
}