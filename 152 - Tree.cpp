#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef unsigned long ul;
const int oo = -1;
struct point
{
	int x, y, z;
	point(int x, int y, int z) : x(x), y(y), z(z) {}
};
int res[10];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y, z;
	vector<point> pt;
	while (cin >> x >> y >> z, x || y || z )
		pt.push_back(point(x, y, z));
	for (int i = 0; i < sz(pt); ++i)
	{
		int mn = INT_MAX;
		for (int j = 0; j < sz(pt); ++j)
		{
			if (i == j) continue;
			int xx = pt[i].x - pt[j].x, yy = pt[i].y - pt[j].y, zz = pt[i].z - pt[j].z;
			mn = min(mn, (int)sqrt(xx * xx + yy * yy + zz * zz));
		}

		if (mn <= 9) res[mn]++;
	}
	for (int i = 0; i < 10; ++i)
		cout << right << setw(4) << res[i];
	cout << endl;
	return 0;
}
