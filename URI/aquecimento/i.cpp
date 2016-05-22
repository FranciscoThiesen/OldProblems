#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
using namespace std;
#define mp make_pair
int main()
{
    int f,c;
    cin >> f >> c;
    vector<pair<int, int> > func;
    vector<int> cli;
    int a;
    priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > fila;
    for(int i =0; i < f; ++i)
    {
        cin >> a;
        pair<int, int> par (i,a);
        fila.push(mp(0, par));
    }
    for(int i =0; i < c; ++i)
    {
        cin >>a;
        cli.push_back(a);
    }
    int totalTime = 0;
    unsigned long long int waitTime = 0;
    for(int i = 0; i < c; ++i)
    {
        auto p = fila.top();
        totalTime = max(totalTime, p.first + (p.second.second * cli[i]));
        fila.push(mp(p.first +  (p.second.second * cli[i]),mp(p.second.first, p.second.second)));
        fila.pop();
    }
    cout << totalTime << endl;
    return 0;


}
