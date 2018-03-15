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
const int oo = 50001;
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
int t, n, m, cost, id;
int kruskal(vector<edge> &p) {
	UnionFind uf(m);
	int mstCost = 0;
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
	string s1, s2;
	map<string, int> names;
	cin >> t;
	rep(tt,0,t)
	{
		cin >> m >> n;
		m++, id = 0, names.clear();
		vector<edge> p;
		rep(i,0,n)
		{
			cin >> s1 >> s2 >> cost;
			if (!names[s1])
				names[s1] = ++id;
			if (!names[s2])
				names[s2] = ++id;
			p.pb(edge(names[s1], names[s2], cost));
		}
		cout << kruskal(p) << "\n" << (tt + 1 != t ? "\n" : "");
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
