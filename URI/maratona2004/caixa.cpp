#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
int main()
{
	int n, m;
	cin >> n >> m;
	while(n != 0)
	{
		int x, y, z;
		cin >> x >> y >> z;
		int volp = x*y*z;
		int t2[3] = {x, y, z};
		vector<int> difvol;
		vector< pair<pair<int, int>, int> > caixas;
		sort(t2, t2+3);
		for(int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			int t1[3] = {a, b, c};
			sort(t1, t1+3);
			bool cabe = true;
			for(int i = 0; i < 3; i++)
			{
				if(t1[i] < t2[i])
					cabe = false;
			}
			if(cabe)
			{

				int volc = a*b*c;
				//so vai para o vetor de tupla caixas que comporta o produto
				caixas.push_back(make_pair(make_pair(t1[0], t1[1]), t1[2]));
			}
		}
		int resp = numeric_limits<int>::max();
		bool fodaci = false;
		if(caixas.empty())
		{
			fodaci  = true;
		}
		else
		{
			vector<pair<pair<int, int>, int> > cpy = caixas;
			for(int i = 0; i < cpy.size(); ++i)
			{
				pair<pair<int, int>, int> k = cpy[i];
				int freq = 0;
				for(int j = 0; j < caixas.size(); ++j)
				{
					if(caixas[j] == cpy[i])
						freq++;
				}
				if(freq >= n)
				{
					int volc = k.fi.fi * k.fi.se * k.se;
					resp = ((volc - volp < resp)? volc - volp : resp);
				}
			}
		}
		if(resp == numeric_limits<int>::max())
		{
			cout << "impossible" << endl;
		}
		else
			cout << resp << endl;
		cin >> n >> m;
	}
	return 0;
}