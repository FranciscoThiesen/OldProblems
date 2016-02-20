/*
ID: francis33
LANG: C++11
TASK: ride
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a;
    string b;
    fin >> a;
    fin >> b;
    int ta = 1;
    int tb = 1;
    for(int i = 0; i < a.size(); i++)
        ta *= a[i] - 'A' + 1;
    for(int j = 0; j < b.size();j++)
        tb *= b[j] - 'A' + 1;
    if(ta%47 == tb%47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;

}
