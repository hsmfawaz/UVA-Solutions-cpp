#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef unsigned long long ul;
const int oo = 1001;
#define EPS 0.0000001
struct Point {
	double x, y;
	Point(double x, double y): x(x), y(y) {}

	Point(): x(0), y(0) {}
	//read and write
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	void print() {
		printf("%.9lf %.9lf", x, y);
	}

	//operators
	Point& operator=(const Point& o) {
		x = o.x;
		y = o.y;
		return *this;
	}

	Point& operator+=(const Point& o) {
		x += o.x;
		y += o.y;
		return *this;
	}

	Point& operator-=(const Point& o) {
		x -= o.x;
		y -= o.y;
		return *this;
	}

	Point& operator*=(double fact) {
		x -= fact;
		y -= fact;
		return *this;
	}
	Point& operator/=(double fact) {
		x /= fact;
		y /= fact;
		return *this;
	}
};

Point any;

//------------------------operators---------------------------
//minus
Point operator-(const Point &a) {
	return Point(-a.x, -a.y);
}


//addition
Point operator+(const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}
//subtraction
Point operator-(const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

//dot product
double operator*(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

//cross product
double operator^(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

//multiplication by a factor
Point operator*(const double factor, const Point & p) {
	return Point(factor * p.x, factor * p.y);
}


Point operator*(const Point & p, const double factor) {
	return Point(factor * p.x, factor * p.y);
}

//-----------------------------segment----------------------------------



struct Segment {
	Point a, ab;
	Segment(const Point &a, const Point &b): a(a), ab(b - a) {}
	Segment(): a(), ab() {}

	Point b () const {
		return a + ab;
	}
};
bool inter(const Segment& s1, const Segment &s2, Point& res = any) {
	if ((s1.ab ^ s2.ab) == 0)return 0; // parallel
	double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
	double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
	if (t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1)return 0; // does not intersect
	res = s1.a + s1.ab * t1;
	return 1;
}
#define inRange(a, b, p, e) ( ((p) >= min(a, b) - (e)) && ((p) <= max(a, b) + (e)) )
#define inRect(a, b, p, e) ( inRange((a).x, (b).x, (p).x, e) && inRange((a).y, (b).y, (p).y, e) )


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	Point p[4];
	for (int t = 0; t < n; ++t)
	{
		for (int tt = 0; tt < 4; ++tt)
			cin >> p[tt].x >> p[tt].y;
		if (p[2].x > p[3].x)
			swap(p[2].x , p[3].x);

		if (p[2].y < p[3].y)
			swap(p[2].y , p[3].y);
		Segment line(p[0], p[1]), rec[4];
		Point rt(p[3].x, p[2].y), rb(p[2].x, p[3].y);
		rec[0] = Segment(p[2], rt), rec[1] = Segment(rt, p[3]);
		rec[2] = Segment(p[3], rb) , rec[3] = Segment(rb, p[2]);
		
		bool flag = (inRect(p[2], p[3], p[0], EPS) || inRect(p[2], p[3], p[1], EPS));

		for (int i = 0; i < 4; ++i)
		{
			if (inter(line, rec[i])) {
				flag = true;
				break;
			}
		}
		if (flag) puts("T");
		else puts("F");

	}
	return 0;
}
