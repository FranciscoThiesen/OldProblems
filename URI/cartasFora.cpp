#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int x = 1;
    while(x != 0)
    {
        scanf("%d", &x);
        if(x == 0)
            break;
        queue<int> fila;
        vector<int> discard;
        for(int i = 1; i <= x; ++i)
            fila.push(i);
        while(fila.size() > 1)
        {
            int a = fila.front();
            discard.push_back(a);
            fila.pop();
            int b = fila.front();
            fila.push(b);
            fila.pop();
        }
        cout << "Discarded cards: ";
        for(int i = 0; i < discard.size(); ++i)
        {
            if(i != discard.size()-1)
                cout << discard[i] << ", ";
            else
                cout << discard[i] << endl;
        }
        cout << "Remaining card: " <<fila.front() << endl;
    }
    return 0;
}
