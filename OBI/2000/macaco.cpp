#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int test = 1;
	while(cin >> n)
	{
		if(!n)break;
		int upLeftX;
		int upLeftY;
		int downRightX;
		int downRightY;
		for(int i = 0; i < n; ++i)
		{
			int lx, ly, rx, ry;
			cin >> lx >> ly >> rx >> ry;
			if(i == 0)
			{
				upLeftY = ly;
				upLeftX = lx;
				downRightY = ry;
				downRightX = rx;

			}
			else
			{
				//algum dos 4 cantos tem que estar dentro da regiao, do contrario, nao ha overlap
				upLeftX = max(upLeftX, lx);
				upLeftY = min(upLeftY, ly);
				downRightX = min(downRightX, rx);
				downRightY = max(downRightY, ry);
			}
		}
		printf("Teste %d\n", test);
		if(downRightX - upLeftX > 0 && upLeftY - downRightY > 0)
		{
			printf("%d %d %d %d\n\n", upLeftX, upLeftY, downRightX, downRightY);
		}
		else
			printf("nenhum\n\n");
		test++;
	}
	return 0;
}