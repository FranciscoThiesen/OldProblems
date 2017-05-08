#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <bitset>
#include <cmath>

#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;

int main()
{
	int C, N;

	while(scanf("%d %d", &C, &N) != EOF)
	{
		unordered_map<int, int> placaSize;
		unordered_map<int, int> placaBegPos;
		vector<int> est(C,0);
		vector<pair<int, int> > segVago;
		segVago.pb(mp(0, C - 1));
		char p;
		int resp = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> p;
			vector<pair<int, int> > aux;
			int car, lenCar;
			if(p == 'C')
			{
				cin >> car >> lenCar;
				for(auto& i : segVago)
				{
					if(i.se - i.fi + 1 >= lenCar && i.fi + i.se >= 0)
					{
						//cout << i.se - i.fi + 1 << "  lenCar" << lenCar << endl;
						//est.set(i.fi, i.fi+lenCar - 1);
						for(int k = i.fi; k < i.fi+lenCar; ++k)
							est[k] = 1;
						resp += 10;
						placaSize[car] = lenCar;
						placaBegPos[car] = i.fi;
						i.fi += lenCar;
						if(i.fi > i.se)
						{
							i.fi = -1;
							i.se = -1;
						}
						int ant = -1;
						int begPos = -1;
						for(int j = 0; j < est.size();++j)
						{
							if(est[j] == 0 && (ant == -1 || ant == 1))
							{
								ant = 0;
								begPos = j;
							}
							else if(est[j] == 1 && ant == 0)
							{
								aux.pb(mp(begPos, j-1));
								ant = 1;
							}
							if(j == est.size()-1 && est[j] == 0)
							{
								aux.pb(mp(begPos, j));
							}
						}
						//for(int u = 0; u < aux.size(); u++)
						//	cout << "AUX: " << aux[u].fi << " " << aux[u].se << endl;
						segVago = aux;
						aux.clear();
						break;
					}
				}

				// if(lenCar <= C)
				// {
				// 	mapCars[car] = lenCar;
				// 	C -= lenCar;
				// 	resp += 10;
				// }
			}
			else
			{
				cin >> car;
				//est.reset(placaBegPos[car], placaSize[car]-1);
				//cout << placaBegPos[car] << "   <- posicao inicial do carro.. tam -> " << placaSize[car] << endl;
				for(int q = placaBegPos[car]; q < placaBegPos[car] + placaSize[car];++q)
					est[q] = 0;
				int ant = -1;
				int begPos = -1;
				for(int j = 0; j < est.size();++j)
				{
					if(est[j] == 0 && (ant == -1 || ant == 1))
					{
						ant = 0;
						begPos = j;
					}
					else if(est[j] == 1 && ant == 0)
					{
						aux.pb(mp(begPos, j-1));
						ant = 1;
					}
					if(j == est.size()-1 && est[j] == 0)
					{
						aux.pb(mp(begPos, j));
					}
				}
				//for(int u = 0; u < aux.size(); u++)
				//	cout << "AUX saida: " << aux[u].fi << " " << aux[u].se << endl;
				segVago = aux;
				aux.clear();
			}
			
		}
		cout  << resp  << endl;

	}
	return 0;
}