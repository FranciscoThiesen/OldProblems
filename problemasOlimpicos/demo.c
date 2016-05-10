#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	int sequenciaAtual = 1;
	int sequenciaMax = 1;
	int numeros[a];
	for(int i = 0; i < a; ++i)
	{
		scanf("%d", &numeros[i]);
	}
	for(int i = 1; i < a; ++i)
	{
		if(numeros[i] == numeros[i-1])
			sequenciaAtual++;
		else
			sequenciaAtual = 1;

		if(sequenciaAtual > sequenciaMax)
			sequenciaMax = sequenciaAtual;
	}
	printf("%d\n",sequenciaMax); 
	return 0;
}