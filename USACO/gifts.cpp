/*
ID: francis33
PROG: gift1
LANG: C++11                
*/
#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <cmath>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    unordered_map<string, int> friends;
    unordered_map<string, int> initial;
    vector<string> order;
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        string name;
        fin >> name;
        friends.insert(make_pair(name,0));
        order.push_back(name);
    }
    for(int j = 0; j < n; j++)
    {
        string loser;
        string receiver;
        float total, people;
        fin >> loser;
        fin >> total >> people;
        initial[loser] = total;
        float share;
        if(people > 0)
        {   
            share = floor(total/people);
            friends[loser] += total - (share*people);
        }
        else
            friends[loser] += total;
        for(int k = 0; k < people; k++)
        {
            fin >> receiver;
            friends[receiver] += share;
        }
    }
    for(int q = 0; q < n; q++)
    {
        fout << order[q] << " " << friends[order[q]] - initial[order[q]] << endl;
    }
    return 0;
    
}
