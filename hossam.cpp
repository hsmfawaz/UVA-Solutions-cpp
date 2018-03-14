#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x,y) memset(x,(y),sizeof x)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 100;
int n, t, x;
vector<set<int>> g(oo);
bool vis[oo];
int dfs(int node) {
	vis[node] = 1;
	int ret = 1;
	for (int i : g[node])
		if (!vis[i])
			ret += dfs(i);
	return ret;
}
void solution() {
	string s;
	while (cin >> n, n) {
		g.assign(n, { });
		clr(vis, 0);

		while (cin >> t, t) {
			getline(cin, s);
			stringstream ss(s);
			while (ss >> x)
				g[x - 1].insert(t - 1), g[t - 1].insert(x - 1);

		}
		int ct = 0;

		rep(i,0,n)
		{
			clr(vis, 0);
			vis[i] = 1;
			t = dfs(i + 1 == n ? 0 : i + 1);
			ct += t != n - 1 ? 1 : 0;
		}
		cout << ct << endl;
	}

}
int main() {
	FastIO;
	solution();
	return 0;
}
