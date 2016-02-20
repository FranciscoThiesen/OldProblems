/*
ID: francis33
PROG: beads
LANG: C++11                
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    fin >> n;
    string necklace;
    fin >> necklace;
    int total[n];
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        int tot = 0;
        char color = 'w';
        if(i == 0)
        {
            for(int j = i; j < n; j++)
            {   
                if(necklace[j] == 'w')
                    tot++;
                else if(necklace[j] != color && color != 'w')
                    break;
                else
                {
                    tot++;
                    color = necklace[j];
                }
            }

        }
        else
        {
            for(int j = i+1; j < n; j++)
            {   
                if(necklace[j] == 'w')
                    tot++;
                else if(necklace[j] != color && color != 'w')
                    break;
                else
                {
                    tot++;
                    color = necklace[j];
                }
            }
        }
        color = 'w';
        if(i == n-1)
        {
            for(int k = i;k >= 0; k++)
            {
                if(necklace[k] == 'w')
                    tot++;
                else if(necklace[k] != color && color != 'w')
                    break;
                else
                {
                    tot++;
                    color = necklace[k];
                }
            }
        }
        else
        {
            for(int k = i-1; k >= 0; k--)
            {
                if(necklace[k] == 'w')
                    tot++;
                else if(necklace[k] != color && color != 'w')
                    break;
                else
                {
                    tot++;
                    color = necklace[k];
                }
            }
        }
        total[i] = tot;
        if(tot >= max)
            max = tot;
    }
    fout << max << endl;
    return 0;
}
