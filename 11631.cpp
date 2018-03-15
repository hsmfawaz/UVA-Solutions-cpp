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
const int oo = 200001;
struct edge {
	int from, to;
	ll weight;
	edge(int f, int t, ll c) {
		from = f, to = t, weight = c;
	}
	bool operator <(const edge &e) const {
		return weight > e.weight;
	}
};
struct UnionFind {
	vector<int> rank, parent;
	UnionFind(int n) {
		rank = vector<int>(n), parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i, rank[i] = 1;
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

};
int t, n, m, cost, tt;
ll kruskal(vector<edge> &p) {
	UnionFind uf(m);
	ll mstCost = 0;
	priority_queue<edge> q;
	for (edge it : p)
		q.push(it);
	while (!q.empty()) {
		edge e = q.top();
		q.pop();
		if (uf.union_sets(e.from, e.to)) {
			mstCost += e.weight;
		}
	}

	return mstCost;
}
void solution() {
	while (cin >> m >> n, m | n) {
		vector<edge> p;
		ll totalcost = 0;
		rep(i,0,n)
		{
			cin >> t >> tt >> cost, totalcost += cost;
			p.pb(edge(t, tt, cost));
		}
		cout << totalcost - kruskal(p) << endl;
	}

}
int main() {
	FastIO;
	solution();
	return 0;
}
