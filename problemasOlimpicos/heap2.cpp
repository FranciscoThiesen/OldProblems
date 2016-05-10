#include <iostream>
#include <vector>
 
using namespace std;
 
int shift_down(vector<int>& heap,int i, int max) {
    int i_big, c1, c2;
    int k = 0;
    while(i < max) {
        i_big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        if( c1<max && heap[c1]>heap[i_big] )
        {
            i_big = c1;
        }
        if( c2<max && heap[c2]>heap[i_big] )
        { 
            i_big = c2;
        }
        if(i_big == i) 
            return k;
        swap(heap[i],heap[i_big]);
        i = i_big;
        k++;
    }
    return k;
}
 
int to_heap(vector<int>& arr) {
    int p = 0;
    int i = (arr.size()/2) - 1;
    while(i >= 0) {
        p += shift_down(arr, i, arr.size());
        --i;
    }
    return p;
}
 
int heap_sort(vector<int>& arr) {
    int k = 0;
    to_heap(arr);
    int end = arr.size() - 1;
    while (end > 0) {
        swap(arr[0], arr[end]);
        k += shift_down(arr, 0, end);
        --end;
    }
    return k;
}
 
int main() {
    vector<int> data = {
        1,2,3,4
    };
    int k = heap_sort(data);
    for(int i : data) cout << i << " " << k << endl;

    return 0;
}