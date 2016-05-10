#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int main()
{
	int alvos, tiros;
	scanf("%d %d", &alvos, &tiros);
	int raios[alvos];
	int posX[tiros];
	int posY[tiros];
	int pontos = 0;
	for(int i = 0; i < alvos; i++)
		scanf("%d" , &raios[i]);

	for (int j = 0; j < tiros; j++)
	{
		scanf("%d %d", &posX[j], &posY[j]);
	} 
		
	for(int k = 0; k < tiros ; k++)
	{
		for(int l = 0; l < alvos; l++)
		{

			if(((posX[k] * posX[k]) + (posY[k] * posY[k])) <= raios[l] * raios[l])
			{
				pontos++;
				printf("tiro %d %d\n", posX[k], posY[k]);
			}
		}

	}

	printf("%d\n", pontos);
	return 0;
}