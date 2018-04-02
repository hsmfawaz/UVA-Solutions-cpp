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
		printf("POINT %0.2f %0.2f\n", x, y);
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


struct Line {
	Point a, ab;
	Line(const Point &a, const Point &b): a(a), ab(b - a) {}
	Line(): a(), ab() {}

	Point b() {
		return a + ab;
	}

};


bool online(const Line& l, Point& p) {
	return ((p - l.a) ^ l.ab) == 0;
}


bool inter(const Line& s1, const Line &s2, Point& res) {
	if ((s1.ab ^ s2.ab) == 0)return 0; // parallel
	double t = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
	res = s1.a + s1.ab * t;
	return 1;
}


int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	puts("INTERSECTING LINES OUTPUT");
	for (int t = 0; t < n; ++t)
	{
		Point p[4];
		for (int i = 0; i < 4; ++i)
			p[i].read();
		Line s1(p[0], p[1]), s2(p[2], p[3]);
		Point res;
		if (inter(s1, s2, res))
			res.print();
		else {
			if (online(s2, p[1]))
				puts("LINE");
			else
				puts("NONE");
		}

	}
	puts("END OF OUTPUT");
	return 0;
}
