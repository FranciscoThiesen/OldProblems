#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
 
// Structure to represent an interval
struct Interval
{
    int low, high;
};
 
// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i;  // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
};
 
// A utility function to create a new Interval Search Tree Node
ITNode *newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;

    return temp;
};
 
// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert.  Here the low value of interval
// is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);
 
    // Get low value of interval at root
    int l = root->i->low;
 
    // If root's low value is smaller, then new interval goes to
    // left subtree
    if (i.low < l)
        root->left = insert(root->left, i);
 
    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);
 
    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;
 
    return root;
}
 
// A utility function to check if given two intervals overlap
bool doOverlap(Interval i1, int x)
{
    if (i1.low <= x && x <= i1.high)
        return true;
    return false;
}
 
// The main function that searches a given interval i in a given
// Interval Tree.
bool overlapSearch(ITNode *root, int x)
{
    // Base Case, tree is empty
    if (root == NULL) 
        return false;
 
    // If given interval overlaps with root
    if (doOverlap(*(root->i), x))
        return true;
 
    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= x)
        return overlapSearch(root->left, x);
 
    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, x);
}
 
// Driver program to test above functions
int main()
{
    // Let us create interval tree shown in above figure
    // Interval ints[] = {{15, 20}, {10, 30}, {17, 19},
    //     {5, 20}, {12, 15}, {30, 40}
    // };
    // int n = sizeof(ints)/sizeof(ints[0]);
    int t;
    int test = 1;
    scanf("%d", &t);
    while(t--)
    {
        int s, n;
        cin >> s >> n;
        ITNode *root = NULL;
        for(int i = 0; i < n; ++i)
        {
            int x, y;

            cin >> x >> y;
            root = insert(root, Interval{x, y});
        }
        int st;
        cin >> st;
        int ans = 0;
        for (int i = 0; i < st; i++)
        {
            int k;
            cin>>k;
            if(overlapSearch(root, k))
                ans++;
        }

        printf("Caso #%d: %d\n", test, ans);
        test++;     
    }
    return 0;
}