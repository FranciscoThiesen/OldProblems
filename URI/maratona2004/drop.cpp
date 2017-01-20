#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main()
{
	int t = 1;
	bool first = true;
	while(t != 0)
	{
		cin >> t;
		if(t == 0)
			break;
		vector<string> names;
		for(int i = 0; i < t; ++i)
		{
			string name;
			cin >> name;
			names.pb(name);
		}

		queue<int> deck;

		//leitura do baralho
		for(int i = 0; i < 52; ++i)
		{
			int x;
			cin >> x;
			deck.push(x);
		}

		int active_players = t;
		
		vector<bool> players(t, true);
		vector<int> winners;
		while(active_players > 1)
		{
			vector<int> ps;
			for(int i = 0; i < t; ++i)
			{
				if(players[i] == true)
				{
					ps.pb(i);
				}
			}
			if(ps.size() > deck.size())
			{
				for(int i = 0; i < ps.size(); ++i)
				{
					winners.pb(ps[i]);
				}
				break;
			}
			int mx = numeric_limits<int>::min();
			int mn = numeric_limits<int>::max();
			vector<int> cards;
			for(int i = 0; i < ps.size(); ++i)
			{
				int card = deck.front();
				deck.pop();
				cards.pb(card);
				if(card > mx)
					mx = card;
				if(card < mn)
					mn = card;

			}
			//tratar o caso em que o maximo eh igual ao minimo
			if(mx != mn)
			{
				for(int i = 0; i < ps.size(); ++i)
				{
					if(cards[i] == mn)
					{
						players[ps[i]] = false;
						active_players--;
					}
				}
			}	
			else
			{
				for(int i = 0; i < ps.size(); ++i)
				{
					winners.pb(ps[i]);
				}
				break;
			}		
		}
		if(!winners.empty())
		{
			for(int i = 0; i < winners.size(); ++i)
			{
				cout << names[winners[i]] << " ";
			}
			cout << endl;
		}
		else
		{
			for(int i = 0; i < players.size(); ++i)
			{
				if(players[i] == true)
				{
					cout << names[i] << " " << endl;
				}
			}
		}
		first = false;
	}
	return 0;
}