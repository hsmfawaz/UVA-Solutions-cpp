#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef long long ll;
const int oo = 1001;
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

double angle(const Point& p) {
	return atan2(p.y, p.x);
}

double angle(const Point& a, const Point& b) {
	return atan2(a ^ b, a * b);
}

Point rotate(const Point &p, double an) {
	return Point(p.x * cos(an) - p.y * sin(an), p.x * sin(an) + p.y * cos(an));
}

Point rotate(const Point &p, double an, Point& around) {
	return rotate(p - around, an) + around;
}

double abs(const Point &p) {
	return p * p;
}

double norm(const Point &p) {
	return sqrt(p * p);
}

Point perp(const Point &p) {
	return Point(-p.y, p.x);
}

Point bisector(const Point &a, const Point &b) {
	return a * norm(b) + b * norm(a);
}
//projection
double proj(const Point &a, const Point &b) {
	return a * b / norm(b);
}
//
#define PI  3.141592653589793
Point ps[51];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); //cout.tie(0);
	int n, t;
	while (cin >> n >> t) {
		for (int i = 1, r, tt; i <= n; ++i)
		{
			cin >> r >> tt;
			Point p(r + ps[i - 1].x, ps[i - 1].y);
			ps[i] = rotate(p, (t / (double)tt) * 2 * PI, ps[i - 1]);
		}
		for (int i = 1; i <= n; ++i)
			cout << fixed << setprecision(4) << norm(ps[i]) << (i + 1 <= n ? " " : "");
		cout << endl;
	}
	return 0;
}
