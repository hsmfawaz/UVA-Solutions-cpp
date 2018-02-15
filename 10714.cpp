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
typedef long long ll;
typedef unsigned long ul;
const int MX = 10e5 + 1;
void Solution() {
	int t;
	cin >> t;
	while (t--) {
		int len, ant, tt;
		cin >> len >> ant;
		int near(0), far(0);
		rep(i,0,ant)
		{
			cin >> tt;
			int nearest = min(tt, len - tt);
			near = max(nearest, near);
			far = max(far, len - nearest);
		}
		cout << near << " " << far << endl;
	}
}
int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
#endif
	Solution();
	return 0;
}
