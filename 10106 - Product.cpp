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
	while (cin >> x >> y) {
		cx = 0;
		memset(f, 0, sizeof f);
		for (int i = sz(x) - 1 ; i >= 0 ; --i, cx++)
		{
			for (int j = sz(y) - 1 , t = 0; j >= 0 ; --j, t++)
			{
				f[cx + t] += (x[i] - '0') * (y[j] - '0');
				if (f[cx + t] >= 10)
					f[cx + t + 1] += f[cx + t] / 10, f[cx + t] %= 10;
			}
		}
		bool q = 0;
		for (int i = 1000; i >= 0; --i)
		{
			if(f[i] > 0 || q)
				cout << f[i],q = 1;
		}
		cout << (!q ? "0" : "") << endl;
	}
	return 0;
}