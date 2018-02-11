#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define clr(x) memset(x,0,sizeof x)
#define ft first
#define sd second
typedef vector<int> vi;
typedef unsigned long long ll;
typedef unsigned long ul;
const int MX = 10e5 + 1;
bool vis[501][501];
void Solution() {
	int x, y, z;
	while (cin >> x >> y >> z, x) {
		clr(vis);
		int res = x * y;
		rep(i, 0, z)
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			rep(j,x1,x2+1)
				rep(w,y1, y2+1)
					if (!vis[j][w])
						vis[j][w] = 1, res--;

		}
		if (!res)
			cout << "There is no empty spots." << endl;
		else if (res == 1)
			cout << "There is one empty spot." << endl;
		else
			cout << "There are " << res << " empty spots." << endl;
	}
}
int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	Solution();
	return 0;
}
