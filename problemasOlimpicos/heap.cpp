/*
 * C++ Program to Implement Heap Sort
 */
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <string>
using namespace std;
int max_heapify(int *a, int i, int n)
{
    int j, temp;
    int k = 0;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
        {
            j = j+1;
        }
        if (temp > a[j])
        {
            break;
        }
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
            k++;
        }
        k++;
    }
    a[j/2] = temp;
    return k;
}
int heapsort(int *a, int n)
{
    int i, temp;
    int k = 0;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        k += max_heapify(a, 1, i - 1);
    }
    return k;
}
int build_maxheap(int *a, int n)
{
    int i;
    int k = 0;
    for(i = n/2; i >= 1; i--)
    {
        k += max_heapify(a, i, n);
    }
    return k;
}

int main()
{
    int n, i, x;
    cout<<"enter no of elements of array\n";
    cin>>n;
    int a[20];
    for (i = 1; i <= n; i++)
    {
        cout<<"enter element"<<(i)<<endl;
        cin>>a[i];
    }
    int p = build_maxheap(a,n);
    cout <<  heapsort(a, n) + p << endl;
    cout<<"sorted output\n";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
    getchar(); 
}