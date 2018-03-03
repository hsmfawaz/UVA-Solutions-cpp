#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x) memset(x,0,sizeof x)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
const int oo = 100;
int t, n, m, k, w;
vector<string> g;
bool vis[oo][oo];
int res[oo][oo];
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
vector<pair<int, int> > attack;
bool safe(int x, int y) {
	return x >= 0 and x < n and y >= 0 and y < m;
}
int dfs(int x, int y) {
	if (!safe(x, y) || vis[x][y] || g[x][y] == 'L')
		return 0;

	attack.push_back( { x, y });
	vis[x][y] = 1;

	int ret = 1;
	rep(i,0,8)
		ret += dfs(x + dx[i], y + dy[i]);

	return ret;

}
void solution() {
	cin >> t;
	string s;
	getline(cin, s);
	getline(cin, s);
	while (t--) {
		clr(vis);
		g.clear();
		while (getline(cin, s), s[0] == 'W' || s[0] == 'L')
			g.pb(s);

		n = sz(g), m = sz(g[0]);

		istringstream is(s);
		is >> k >> w, --k, --w;
		vector<pair<int, int> > defence;
		defence.pb( { k, w });
		while (getline(cin, s)) {
			if (s.empty())
				break;
			istringstream is2(s);
			is2 >> k >> w, --k, --w;
			defence.pb( { k, w });
		}
		for (auto u : defence) {
			if (!vis[u.ft][u.sd]) {
				int ret = dfs(u.ft, u.sd);
				for (auto u : attack)
					res[u.ft][u.sd] = ret;
				attack.clear();
			}
			cout << res[u.ft][u.sd] << endl;
		}
		cout << (t - 1 >= 0 ? "\n" : "");
	}
}
int main() {
	//FastIO;
	solution();
	return 0;
}
