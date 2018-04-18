#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef long long ll;
const int oo = 10e6 + 1;
int f[1001], cx;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string x, y;
	int n;
	cin >> n;
	while (n--) {
		cx = 0;
		memset(f, 0, sizeof f);
		cin >> x >> y;
		if (sz(x) < sz(y)) swap(x, y);
		int ct = 0;
		for (int i = 0 ; i < sz(x) ; i++)
		{
			f[i] += (x[i] - '0') + (i < sz(y) ? (y[i] - '0') : 0) + ct;
			ct = f[i] / 10;
			f[i] %= 10;
		}
		bool q = 0;
		for (int i = 0; i <  sz(x); ++i)
		{
			if (f[i] > 0 || q)
				cout << f[i], q = 1;
		}
		cout << (ct ? to_string(ct) : "") << endl;
	}
	return 0;
}