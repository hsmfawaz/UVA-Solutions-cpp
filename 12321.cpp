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
	int l, g, t, tt;
	while (cin >> l >> g, l) {
		vector<pair<int, int> > gs(g);
		rep(i,0,g)
			cin >> t >> tt, gs[i] = {t-tt,t+tt};
		sort(all(gs));
		int i = 0, j = 0, res = g;
		while (i < l) {
			int curpos = i;
			while (gs[j].first <= i and j < g)
				curpos = max(curpos, gs[j++].second);
			if (curpos == i)
				break;
			i = curpos;
			--res;
		}
		cout << (i < l ? -1 : res) << endl;

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
