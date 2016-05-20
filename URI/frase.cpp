#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        string frase;
        getline(cin, frase);
        unordered_set<int> lets;
        for(int i = 0; i < frase.size(); ++i)
        {
            if(frase[i] != ',' && frase[i] != ' ')
                lets.insert(frase[i]);
        }
        if(lets.size() >= 26)
            cout << "frase completa" << endl;
        else if(lets.size() > 12)
            cout << "frase quase completa" << endl;
        else
            cout << "frase mal elaborada" << endl;
    }
    return 0;
}
