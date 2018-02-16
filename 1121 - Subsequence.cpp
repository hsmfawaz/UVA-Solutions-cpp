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
const int MX = 1000001;
void Solution() {
	int n, s;
	while (cin >> n >> s) {
		int x[n];
		bool finish = false;
		rep(i,0,n)
			cin >> x[i];

		for (int k = 1; k < n and !finish; k++) {
			int mx = 0;
			rep(i,0,k)
				mx += x[i];

			rep(i,k,n)
			{
				if (mx >= s) {
					cout << k << endl;
					finish = true;
					break;
				}
				mx += x[i] - x[i - k];
			}
		}
		if (!finish)
			cout << 0 << endl;
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
