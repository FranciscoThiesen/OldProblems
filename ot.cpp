#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
using namespace std;

struct Point
{
    int x;		//contains x-cordinate of point
    int y;		//contains y-cordinate of point
	int index;	//contains line number for point
	int leftNode; //flag to check point is left end of its line
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See http://w...content-available-to-author-only...s.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

// This function finds predecessor and successor of key in BST.
// It sets pre and succ as predecessor and successor respectively
void findPreSuc(map<int, Point> mp, Point &pre, Point &succ, 
	Point key, bool &predecessorSet, bool &successorSet)
{
	map<int, Point>::iterator it;
	for (it=mp.begin(); it!=mp.end(); it++)
	{
    	if(it->first < key.y) {
    		pre = it->second;
			predecessorSet = true;
    	} else if(it->first > key.y) {
    		succ = it->second;
			successorSet = true;
    		break;
    	}
	}
}

//Store all active line segments in the BST and
//find out if any two line segments intersect or not.
bool processBST(Point nextMin, map<int, Point> &mp, vector<Point>& p, vector<Point>& q)
{
    Point pre, succ;
	bool predecessorSet = false, successorSet = false;
	// Find predecessor and successor of next leftmost point	
    findPreSuc(mp, pre, succ, nextMin, predecessorSet, successorSet);
	
    // If this point is left end of its line
    if(nextMin.leftNode)
	{
		mp.insert(pair<int, Point>(nextMin.y, nextMin));

		// Check if this points intersects with its predecessor
		if(predecessorSet)
		{
			if(pre.leftNode)
				if(doIntersect(nextMin, q[nextMin.index], pre, q[pre.index]))
					return true;
			else
				if(doIntersect(nextMin, q[nextMin.index], p[pre.index], pre))
					return true;
		}

		// Check if this points intersects with its successor
		if(successorSet)
		{
			if(succ.leftNode)
				return doIntersect(nextMin, q[nextMin.index], succ, q[succ.index]);
			else
				return doIntersect(nextMin, q[nextMin.index], p[succ.index], succ);
		}
    } else { // If it's a right end of its line
	     // Check if its predecessor and successor intersect with each other
		if(predecessorSet && successorSet)
		{
			if(pre.leftNode)
			{
				if(succ.leftNode)
					return doIntersect(pre, q[pre.index], succ, q[succ.index]);
				else
					return doIntersect(pre, q[pre.index], p[succ.index], succ);
			} else {
				if(succ.leftNode)
					return doIntersect(p[pre.index], pre, succ, q[succ.index]);
				else
					return doIntersect(p[pre.index], pre, p[succ.index], succ);
			}
		}
		// Delete from tree
		mp.erase (p[nextMin.index].y); // erasing by key
    }
	return false;
}

struct compare
{
   bool operator()(const Point& l, const Point& r)
   {
       return l.x > r.x;
   }
};

/* Function to find if any two segments intersect on
given n line segments using Sweep Line Algorithm */
int sweepLineIntersection(vector<Point>& p , vector<Point>& q, int N)
{
	unsigned long long ans = 0;
	// Create a priority queue with 2N heap nodes.
   	std::priority_queue<Point, std::vector<Point>, compare > pq;
    for(int i = 0; i < 2 * N; i++) 
    {
		if(i < N) pq.push(p[i]);
		else pq.push(q[i - N]);
    }

	//Create an empty std::map (internally uses Self-Balancing BST)
	//It will contain all active line Segments ordered by y coordinate.
    map<int, Point> mp;

    // Now one by one get the minimum element from minheap
    while (!pq.empty()) {
		// Get the minimum element and pass it to processBST
	   Point min = pq.top();
		if(processBST(min, mp, p, q))
			ans++;
		
		pq.pop();
    }
	return ans;
}

/* Driver program to test above function*/
int main()
{
	// Point p[] = { { 1, 6, 0, 1 }, { 2, 9, 1, 1 }, { 3, 3, 2, 1 }, { 9, 8, 3, 1 }, { 10, 2, 4, 1 } };
 //    Point q[] = { { 6, 6, 0, 0 }, { 15, 2, 1, 0 }, { 15, 6, 2, 0 }, { 14, 8, 3, 0 }, { 13, 2, 4, 0 } };
    
    vector<Point> p;
    vector<Point> q;

    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    for(int i = 0; i < k; ++i)
    {
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	Point pt;
    	pt.x = a;
    	pt.y = b;
    	pt.index = i;
    	pt.leftNode = 1;
    	p.pb(pt);
    	Point pt2;
    	pt2.x = c;
    	pt2.y = d;
    	pt.index = i;
    	pt.leftNode = 0;
    	q.pb(pt2);
    }
    /*//change N = 4
    Point p[] = { { 1, 6, 0, 1 }, { 2, 9, 1, 1 }, { 9, 8, 2, 1 }, { 10, 2, 3, 1 } };
    Point q[] = { { 6, 6, 0, 0 }, { 15, 2, 1, 0 }, { 14, 8, 2, 0 }, { 13, 2, 3, 0 } };*/

    // function to find if any two segments intersect
    // on given n line segments
    cout << sweepLineIntersection(p, q, k) << '\n';

    return 0;
}
