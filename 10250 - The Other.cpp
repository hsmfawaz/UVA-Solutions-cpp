#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef unsigned long long ul;
const int oo = 1001;
# define M_PI 3.14159265358979323846
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

//comparisons
bool operator==(const Point & a, const Point & b) {
	return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point & a, const Point & b) {
	return a.x != b.x || a.y != b.y;
}


//---------------------functions----------------------
Point rotate(const Point &p, double an) {
	return Point(p.x * cos(an) - p.y * sin(an), p.x * sin(an) + p.y * cos(an));
}

Point rotate(const Point &p, double an, Point& around) {
	return rotate(p - around, an) + around;
}
//
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Point p[2];
	while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y) {
		Point Cen((p[0].x + p[1].x) / 2, (p[0].y + p[1].y) / 2 );
		Point x = rotate(p[0], M_PI / 2, Cen), y = rotate(p[0], -M_PI / 2, Cen);
		x.print(), printf(" "), y.print(), printf("\n");
	}
	return 0;
}
