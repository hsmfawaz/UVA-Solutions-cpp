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
bool valid(pair<int, int> s) {
	return s.ft >= 1 and s.sd >= 1 and s.ft < 9 and s.sd < 9;
}
int bfs(pair<int, int> s, pair<int, int> end) {
	if (s != end) {
		map<pair<int, int>, int> len;
		queue<pair<int, int> > q;
		pair<int, int> cur;
		q.push(s), len[s] = 0;

		int dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
		int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
		int dep = 0, sz = 1;
		for (; !q.empty(); ++dep, sz = q.size()) {
			while (sz--) {
				cur = q.front(), q.pop();

				for (int d = 0; d < 8; ++d) {
					pair<int, int> newp;
					newp.ft = cur.first + dx[d];
					newp.sd = cur.second + dy[d];

					if (len.count(newp) != 0 || !valid(newp))
						continue;

					q.push(newp), len[newp] = dep + 1;

					if (newp.first == end.ft && newp.second == end.sd) {
						return dep + 1;
					}
				}
			}
		}
	}

	return 0;
}
void Solution() {
	char x, y; int d1, d2;
	while (cin >> x >> d1 >> y >> d2) {
		pair<int, int> s = { x - 'a' + 1, d1 }, end = { y - 'a' + 1, d2 };
		int mov = bfs(s, end);
		cout << "To get from " << x << d1 << " to " << y << d2 << " takes "
				<< mov << " knight moves.\n";
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
