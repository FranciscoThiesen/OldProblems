/*input
6
ba 2 16 18
a 1 12
b 3 4 13 20
bb 2 6 8
ababbbbbaab 1 3
abababbbbb 1 1
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000005;
int n, x, cont, occ, st[maxn];
char resp[maxn];

vector<string> ptt;
string tmp;


int main()
{
	for(int i = 0; i < maxn; ++i) st[i] = -1;
	cin >> n;
	int last = 0;
	while(n--)
	{
		cin >> tmp >> x;
		int sz = tmp.size();
		while(x--){
			cin >> occ;
			--occ;
			last = max(last, occ + sz);
			if(st[occ] == -1) st[occ] = cont;
			else{
				if(ptt[st[occ]].size() <= sz)
					st[occ] = cont;
			}
		}
		ptt.push_back(tmp);

		cont++;
	}
	int prevStart = -1;
	int prevSize = -1;
	int tmpIdx, tmpPrev, tmpSize;
	int prevIdx = -1;
	int reach = -1;
	for(int i = 0; i < last; ++i)
	{
		if(st[i] != -1)
		{
			//cout << "Tenho o padrao " << ptt[st[i]] << " comecando na posicao " << i << endl;
			//cout << "alcance atual = " << reach << endl;
			if(i + (int)ptt[st[i]].size() > reach){
				prevIdx = st[i];
				prevStart = i;
				prevSize = ptt[st[i]].size();
				reach = i + prevSize;
			}
		}
		if(prevStart + prevSize - 1 < i)
		{
			//cout << prevStart << " " << prevSize << endl;
			//if(i == 9) cout << "xablau" << endl;
			resp[i] = 'a';
		}
		else
		{ 
			resp[i] = ptt[prevIdx][i-prevStart];
		}
		cout << resp[i];
	}
	return 0;
}