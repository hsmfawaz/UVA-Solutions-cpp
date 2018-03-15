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
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 101;
struct edge {
	int from, to, weight;
	edge(int f, int t, int c) {
		from = f, to = t, weight = c;
	}
	bool operator <(const edge &e) const {
		return weight > e.weight;
	}
};
struct UnionFind {
	vector<int> rank, parent;
	vector<edge> edges;
	int number;
	UnionFind(int n) {
		number = n;
		rank = vector<int>(n), parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i, rank[i] = 1;
	}
	void addEdge(int x, int y, int cost) {
		edges.pb(edge(x, y, cost));
	}
	int find_set(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find_set(parent[x]);
	}

	bool same_set(int x, int y) {
		return find_set(x) == find_set(y);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			link(x, y);
		}
		return x != y;
	}

	vector<vii> Kruskal() {
		priority_queue<edge> q;
		for (edge it : edges)
			q.push(it);
		vector<vii> ret(number);
		while (!q.empty()) {
			edge e = q.top();
			q.pop();
			if (union_sets(e.from, e.to)) {
				ret[e.from].pb( { e.to, e.weight }), ret[e.to].pb(
						{ e.from, e.weight });
			}

		}
		return ret;
	}

};
int t, n, m, cost, tt, q, solve = 0;
bool vis[oo];
vector<vii> edges;
bool dfs(int node, int parent) {
	if (parent == node)
		return 1;
	vis[node] = 1;
	bool found = 0;
	for (int i = 0; i < sz(edges[node]) and !found; i++) {
		pair<int, int> child = edges[node][i];
		if (!vis[child.ft]) {
			found = dfs(child.ft, parent);
			if (found)
				solve = max(solve, child.sd);
		}
	}
	return found;
}
void solution() {
	int ct = 0;
	while (cin >> m >> n >> q, m | n) {
		ct++;
		UnionFind uf(m);
		rep(i,0,n)
			cin >> t >> tt >> cost, uf.addEdge(t - 1, tt - 1, cost);
		edges = uf.Kruskal();
		cout << (ct != 1 ? "\n" : "") << "Case #" << ct << endl;
		rep(i,0,q)
		{
			cin >> t >> tt, --t, --tt;
			clr(vis, 0);
			solve = 0;
			if (!dfs(t, tt)) {
				cout << "no path" << endl;
			} else {
				cout << solve << endl;
			}
		}
	}

}
int main() {
	FastIO;
	solution();
	return 0;
}
