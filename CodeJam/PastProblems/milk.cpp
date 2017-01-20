#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("in.txt");
	fout.open("out.txt");
	if (!fin.is_open())
		cout << "Arquivo de entrada nao foi aberto" << endl;
	else
	{
		int t = 1;
		int cases;
		fin >> cases;
		vector<int> maltedpref; //array for storing the favourite malted milkshake for each client... if a client does not like any malted milkshake value will be -1
		vector<unordered_set<int> > unmaltedpref; // array for storing all the favourite unmalted milkshakes for each client... Maybe using unordered_set here was overkill..

		while (cases--)
		{
			int totalFlavours, clients, qnt, flavour, malt;
			fin >> totalFlavours;
			fin >> clients;
			unordered_map<int, vector<int> > UnmaltedFlavourClients;// hash ( unmaltedFlavour -> Clients)
			unordered_map<int, vector<int> > MaltedFlavourClients;// hash ( maltedFlavour -> Clients)
			vector<int> vals(totalFlavours, 0);//array for storing if a determined flavour should be malted or not(0 for unmalted, 1 for malted)...  use of bitset is also possible, but it is a future silly optimization
			vector<int> favCount(clients, 0);// array for storing the number of favourite milkshakes of a client are going to be prepared
			maltedpref.resize(clients);
			fill(maltedpref.begin(), maltedpref.end(), -1);
			unmaltedpref.resize(clients);
			for (int i = 0; i < clients; ++i)
			{
				fin >> qnt;
				for (int j = 0; j < qnt; ++j)
				{
					fin >> flavour >> malt;
					// flavours are given from 1 to n, that is the reason behind the - 1
					if (malt)
					{
						maltedpref[i] = flavour - 1;
						MaltedFlavourClients[flavour - 1].push_back(i);
					}
					else
					{
						unmaltedpref[i].insert(flavour - 1);
						UnmaltedFlavourClients[flavour - 1].push_back(i);
					}
				}
			}
			bool possible = true;// to check if it is possible to satisfy all the clients

			//setting all the flavoures that can only be malted
			for (int i = 0; i < clients; ++i)
			{
				if (unmaltedpref[i].empty())
				{
					if (maltedpref[i] != -1)
					{
						vals[maltedpref[i]] = 1;
						favCount[i]++;
						for (auto& p : MaltedFlavourClients[maltedpref[i]])
							favCount[p]++;
					}
				}
			}
			//counting the number of favourites for each client 
			for (int i = 0; i < totalFlavours; ++i)
			{
				if (vals[i] == 0)
				{
					for (auto& p : UnmaltedFlavourClients[i])
						favCount[p]++;
				}
			}
			// heap for inserting clients with 0 favourite flavours among the flavours that are going to be prepared
			// ii = pair<index of the Client, index of his malted favourite flavour(if he has one)> .... if he does´t not have a malted favourite then he is insatisfiable
			priority_queue<ii, vector<ii>, greater<ii> > fila;

			//populating heap
			for (int i = 0; i < clients; ++i)
			{
				if (!favCount[i])
				{
					if (maltedpref[i] == -1)
					{
						possible = false;
					}
					else
					{
						fila.push(mp(i, maltedpref[i]));
					}
				}
			}

			//malting the flavours that are necessary according to your idea (: and updating the number of favourites for each client affected by the changes
			if(possible)
			{
				while (!fila.empty())
				{
					ii topo = fila.top();
					fila.pop();
					vals[maltedpref[topo.first]] = 1;
					for (auto& p : MaltedFlavourClients[maltedpref[topo.first]])
						favCount[p]++;
					for (auto& p : UnmaltedFlavourClients[maltedpref[topo.first]])
					{
						favCount[p]--;
						if (favCount[p] == 0)
						{
							if (maltedpref[p] == -1)
							{
								possible = false;
								break;
							}
							else
							{
								fila.push(mp(p, maltedpref[p]));
							}
						}
					}
					if (!possible)
						break;
				}
			}
			if (possible)
			{
				fout << "Case #" << t << ": ";
				for (int i = 0; i < totalFlavours; ++i)
					fout << vals[i] << " ";
				fout << endl;
			}
			else if (!possible)
				fout << "Case #" << t << ": IMPOSSIBLE" << endl;
			t++;
			//cleaning containers that are common to all test cases
			for (auto& p : unmaltedpref)
				p.clear();
			unmaltedpref.clear();
			maltedpref.clear();
		}	
	}
	fout.close();
	fin.close();
	return 0;
}