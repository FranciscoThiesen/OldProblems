/*input
20 16
9 6 5
16 14 8 14
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
#define PRINT(x...) TRACE(printf(x))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

// If using C++11, change __typeof__ to decltype
#define _for(i, a, b) for (decltype(a) i = (a); i != (b); ++i)
#define foreach(x...) _for(x)
#define forall(i, v) foreach(i, all(v))
// If using C++11, change __typeof__ to decltype
#define FU(i, a, b) for(decltype(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define fi first
#define se second
#define mset(c, v) memset(c, v, sizeof(c))
#define mod(a, b) ((((a)%(b))+(b))%(b))
#define pb push_back
#define sz(c) int((c).size())
#define mp make_pair

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-12;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point { 
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}

	// Only type in the operators you actually need
	point operator +(point q) const { return point(x + q.x, y + q.y); }
	point operator -(point q) const { return point(x - q.x, y - q.y); }
	point operator *(double t) const { return point(x * t, y * t); }
	point operator /(double t) const { return point(x / t, y / t); }
	// dot product
	double operator *(point q) const { return x * q.x + y * q.y; }
	// "cross" product (actually "signed area of the quadrilateral"
	double operator %(point q) const { return x * q.y - y * q.x; }
	// uses "cmp" from the template
	int cmp(point q) const {
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) <  0; }
	
	friend ostream& operator <<(ostream& o, point p) {
		return o << "(" << p.x << ", " << p.y << ")";
	}
	
	static point pivot; // only needed for convex hull
};

point point::pivot; // only needed for convex hull

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef vector<point> polygon;

// decides type of turn pqr. 1 if left, -1 if right, 0 if straight
inline int ccw(point p, point q, point r) {
	return cmp((p - r) % (q - r));
}

// angle of turn pqr
inline double angle(point p, point q, point r) {
	point u = p - q, v = r - q;
	return atan2(u % v, u * v);
}

////////////////////////////////////////////////////////////////////////////////
// Is q inside [p,r]? (all segments are closed)
// 

bool between(point p, point q, point r) {
	return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}

////////////////////////////////////////////////////////////////////////////////
// Do segments [p,q] and [r,s] have an intersection?
//

bool seg_intersect(point p, point q, point r, point s) {
	point A = q - p, B = s - r, C = r - p, D = s - q;
	int a = cmp(A % C) + 2 * cmp(A % D);
	int b = cmp(B % C) + 2 * cmp(B % D);
	if (a == 3 || a == -3 || b == 3 || b == -3) return false;
	if (a || b || p == r || p == s || q == r || q == s) return true;
	int t = (p < r) + (p < s) + (q < r) + (q < s);
	return t != 0 && t != 4;
}

////////////////////////////////////////////////////////////////////////////////
// Distance from r to [p,q]
// 

double seg_distance(point p, point q, point r) {
	point A = r - q, B = r - p, C = q - p;
	double a = A * A, b = B * B, c = C * C;
	if (cmp(b, a + c) >= 0) return sqrt(a);
	else if (cmp(a, b + c) >= 0) return sqrt(b);
	else return fabs(A % B) / sqrt(c);
}

////////////////////////////////////////////////////////////////////////////////
// Classifies p with respect of polygon T (not necessarily convex)
// 
// Returns -1 if on border, 0 if outside, 1 if inside
// 

int in_poly(point p, polygon& T) { 
	double a = 0; int N = T.size();
	for (int i = 0; i < N; i++) {
		if (between(T[i], p, T[(i+1) % N])) return -1;
		a += angle(T[i], p, T[(i+1) % N]);
	}
	return cmp(a) != 0;
}
////////////////////////////////////////////////////////////////////////////////
// Convex Hull! O(nlogn), *alters the input T*
//

bool radial_lt(point p, point q) {
	point P = p - point::pivot, Q = q - point::pivot;
	double R = P % Q;
	if (cmp(R)) return R > 0;
	return cmp(P * P, Q * Q) < 0;
}

polygon convex_hull(vector<point>& T) {
	int j = 0, k, n = T.size(); polygon U(n);

	point::pivot = *min_element(all(T));
	sort(all(T), radial_lt);
	// If colinear points are part of hull, insert next two lines
	//for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
	//reverse((k+1) + all(T));

	for (int i = 0; i < n; i++) {
		// If colinear points are part, change >= to >
		while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
		U[j++] = T[i];
	}
	U.erase(j + all(U));
	return U;
}

////////////////////////////////////////////////////////////////////////////////
// Computes the (oriented) area of T. Positive if counterclockwise
//

double poly_area(const polygon& T) {
	double s = 0; int n = T.size();
	for (int i = 0; i < n; i++)
		s += T[i] % T[(i+1) % n];
	return s / 2;
}

////////////////////////////////////////////////////////////////////////////////
// Finds intersection between lines (p,q) and (r,s)
// (Warning: Divides by zero if parallel! Will return NaN or INF in this case)

point line_intersect(point p, point q, point r, point s) {
	point a = q - p, b = s - r, c = point(p % q, r % s);
	return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}





////////////////////////////////////////////////////////////////////////////////
// Find the smallest circle containing all the points in expected time O(N)
//

typedef pair<point, double> circle; // center, radius

bool in_circle(circle C, point p) { // is point p in circle C?
	return cmp((p - C.first)*(p - C.first), C.second*C.second) <= 0;
}

// Given three (not colinear) points, finds center of circle containing them
point circumcenter(point p, point q, point r) {
	point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
	return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

circle spanning_circle(vector<point>& T) {
	int n = T.size();
	random_shuffle(all(T)); // Extremely important!
	circle C(point(), -INFINITY);
	for (int i = 0; i < n; i++) if (!in_circle(C, T[i])) {
		C = circle(T[i], 0);
		for (int j = 0; j < i; j++) if (!in_circle(C, T[j])) {
			C = circle((T[i] + T[j]) / 2, abs(T[i] - T[j]) / 2);
			for (int k = 0; k < j; k++) if (!in_circle(C, T[k])) {
				point o = circumcenter(T[i], T[j], T[k]);
				C = circle(o, abs(o - T[k]));
			}
		}
	}
	return C;
}

////////////////////////////////////////////////////////////////////////////////
// Find the intersection of two CONVEX polygons in LINEAR TIME
//
// P and Q should be in counterclockwise order (their areas should be positive)

polygon poly_intersect(polygon& P, polygon& Q) {
	int m = Q.size(), n = P.size();
	if (m == 0 || n == 0) return polygon();
	int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
	polygon R;
	while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
		point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
		point A = p2 - p1, B = q2 - q1;
		int cross = cmp(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
		if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A * B) < 0) {
			if (between(p1, q1, p2)) R.push_back(q1);
			if (between(p1, q2, p2)) R.push_back(q2);
			if (between(q1, p1, q2)) R.push_back(p1);
			if (between(q1, p2, q2)) R.push_back(p2);
			if (R.size() < 2) return polygon();
			inflag = 1; break;
		} else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
			if (inflag == 0) aa = ba = 0;
			R.push_back(line_intersect(p1, p2, q1, q2));
			inflag = (hb > 0) ? 1 : -1;
		}
		if (cross == 0 && hb < 0 && ha < 0) return R;
		bool t = cross == 0 && hb == 0 && ha == 0;
		if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
			if (inflag == -1) R.push_back(q2);
			ba++; b++; b %= m;
		} else {
			if (inflag == 1) R.push_back(p2);
			aa++; a++; a %= n;
		}
	}
	if (inflag == 0) {
		if (in_poly(P[0], Q)) return P;
		if (in_poly(Q[0], P)) return Q;
	}
	R.erase(unique(all(R)), R.end());
	if (R.size() > 1 && R.front() == R.back()) R.pop_back();
	return R;
}


int main()
{
	int w, h;
	sc2(w, h);
	map<pair<int, int>, pair<double, double> > mat;
	fu(l, h)
	{
		fu(c, w)
		{
			mat[mp(l,c)] = mp((double)(l)+0.5, (double)(c) + 0.5);
		}
	}
	int x, y, r;
	sc3(x, y, r);

	double z1 = mat[mp(y, x)].fi;
	double z2 = mat[mp(y, x)].se;

	circle ci{point(z2, z1), r};

	double x1, y1, x3, y3;
	cin >> x1 >> y1 >> x3 >> y3;
	auto v1 = mat[mp(y1, x1)];
	auto v3 = mat[mp(y3, x3)];
	x1 = v1.se;
	y1 = v1.fi;
	x3 = v3.se;
	y3 = v3.fi;



	double x2 = (x1 + x3 + y3 - y1)/2; double y2 = (y1 + y3 + x1 - x3)/2;
	double x4 = (x1 + x3 + y1 - y3)/2; double y4 = (y1 + y3 + x3 - x1)/2;

	polygon sqr{point(x1, y1), point(x2, y2), point(x3, y3), point(x4, y4)};
	//polygon sqr2 = convex_hull(sqr);
	fu(l, h)
	{
		fu(c, w)
		{
			auto k = mat[mp(l, c)];
			if(in_poly(point(k.se, k.fi), sqr) || in_circle(ci, point(k.se, k.fi)))  cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
	return 0;


}
