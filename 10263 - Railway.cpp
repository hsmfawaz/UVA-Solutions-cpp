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
		cin >> x >> y;
	}
	void print() {
		cout << fixed << setprecision(4) << x << endl << y << endl;
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


//--------------------------------------lines------------------------------------------------


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


double dist(const Line& l, Point& p) {
	return abs(((p - l.a)^l.ab) / norm(l.ab));
}

bool inter(const Line& s1, const Line &s2, Point& res) {
	if ((s1.ab ^ s2.ab) == 0)return 0; // parallel
	double t = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
	res = s1.a + s1.ab * t;
	return 1;
}

double proj(const Point &p, const Line &l, Point &res) {
	res = l.a;
	res += l.ab *  ( ((p - l.a) * l.ab) / abs(l.ab) );
}
void reflection(const Point &p, const Line &l, Point &res) {
	proj(p, l, res);
	res = 2 * res - p;
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


bool onsegment(const Segment& r, const Point& p) {
	return ((p - r.a) ^ r.ab) == 0 && ((p - r.a) * (p - r.b())) <= 0;
}


void  proj(const Point &p, const Segment &l, Point &res){
    res = l.a;
    res += l.ab *  ( ((p - l.a) * l.ab) / abs(l.ab) );
}

double dist(const Segment& r, const Point& p, Point &res = any){
	if((p - r.a) * (r.ab) <= 0) {
		res = r.a;
		return norm(p - r.a);
	}
	if((p - r.b()) * (-r.ab) <= 0) {
		res =  r.b();
		return norm(p - r.b());
	}

	proj(p, r, res);
    return abs(((p-r.a)^r.ab)/norm(r.ab));
}




bool bet(const Segment &s1, const Segment &s2, const Point &p) {
	return (dist(s1, p) + dist(s2, p) == dist(s2, s1.a));
}




int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); //cout.tie(0);
	Point M, Res; int n;
	while (cin >> M.x >> M.y >> n) {
		vector<Point> p(n + 1);
		p[0].read();
		int idx = 0;
		double mn = 10e9;
		for (int i = 1; i <= n; idx = i, ++i) {
			p[i].read();
			Segment s(p[idx], p[i]);
			double dst = dist(s, M);
			if ( dst < mn)
				mn = dst, Res = any;
		}
		Res.print();
	}
	return 0;
}
