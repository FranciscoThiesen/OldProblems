//
//  main.cpp
//  grd
//
//  Created by francisco on 10/05/16.
//  Copyright © 2016 francisco. All rights reserved.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> numz;
    while(n--)
    {
        int a;
        cin >> a;
        numz.push_back(a);
    }
    int high = max(numz[0], numz[1]);
    int low = min(numz[0], numz[1]);
    int diff = high - low;
    for(int i = 1; i < numz.size(); ++i)
    {
        if(numz[i] < low)
            low = numz[i];
        else if(numz[i] > high)
            high = numz[i];
        diff = min(diff, high-low);
    }
    cout << diff << endl;
    return 0;
}

