#include <stdio.h>



int main()
{
	int numDivisoes, resp;
	scanf("%d", &numDivisoes);
	int numPedacos[numDivisoes];
	for(int i = 0; i < numDivisoes; i++)
	{
		scanf("%d",&numPedacos[i]);
		if(i == 0)
			resp += numPedacos[i];
		else
			resp += numPedacos[i] - 1;
	}	
	resp -= 1;
	printf("%d \n", resp);
	return 0;
}