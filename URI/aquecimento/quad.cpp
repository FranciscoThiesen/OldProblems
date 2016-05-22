#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int y, x,a;
    scanf("%d %d", &y, &x);
    int mat[201][201];
    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            cin >> a;
            if(a != 0)
                mat[j][i] = 1;
            else
                mat[j][i] = 0;
        }
    }
    int nq;
    scanf("%d", &nq);
    vector<int> qntd(min(y,x)+1, -1);
    for(int q = 0; q < nq; q++)
    {
        int size;
        scanf("%d", &size);
        vector<bool> seq;
        bool can = false;
        int begY = 0;
        int begX = 0;
        while(true)
        {
            for(int h = 0; h < y; ++h)
            {
                bool isZero = false;
                for(int w = begX; w < begX + size; ++w)
                {
                    if(mat[w][h] == 0)
                    {
                        isZero = true;
                        break;
                    }
                }
                if(isZero == false)
                    seq.push_back(true);
                else
                    seq.push_back(false);
            }
            int cur = 0;
            bool pode = false;
            for(int i = 0; i < seq.size(); ++i)
            {
                if(seq[i] == true)
                    cur++;
                if(cur == size)
                {
                    pode = true;
                    break;
                }
                if(seq[i] == false)
                    cur = 0;
            }
            seq.clear();
            if(pode)
            {
                can = true;
                break;
            }
            else
                begX++;
            if(begX > x-size)
                break;
        }
        if(can)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
