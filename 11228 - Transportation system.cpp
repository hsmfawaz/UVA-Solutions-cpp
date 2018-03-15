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
	bool del;
	edge(int f, int t, int c, bool d = false) {
		from = f, to = t, weight = c;
		del = d;
	}
	bool operator <(const edge &e) const {
		return weight > e.weight;
	}
	bool operator ==(const edge & e) const {
		return (from == e.from && to == e.to && weight == e.weight);
	}
};
struct UnionFind {
	vector<int> rank, parent;
	vector<edge> edges;
	int number;
	UnionFind(int n) {
		number = n;
		rank = vector<int>(number), parent = vector<int>(number);
		for (int i = 0; i < number; i++)
			parent[i] = i, rank[i] = 1;
	}
	void clear() {
		rank = vector<int>(number), parent = vector<int>(number);
		for (int i = 0; i < number; i++)
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

	vector<edge> Kruskal() {
		priority_queue<edge> q;
		for (edge it : edges)
			q.push(it);
		vector<edge> taken;
		while (!q.empty()) {
			edge e = q.top();
			q.pop();
			if (union_sets(e.from, e.to))
				taken.pb(e);
		}
		return taken;
	}
};
int t, n, m, nn, mm, c;
pair<int, int> cord[1001];
int Dist(int i, int j) {
	int x = cord[i].ft - cord[j].ft, y = cord[i].sd - cord[j].sd;
	return x * x + y * y;
}
void solution() {
	cin >> t;
	rep(tt,0,t)
	{
		cin >> n >> m;
		UnionFind uf(n);
		map<ii, int> mp;
		int id = -1;
		rep(i,0,n)
		{
			cin >> cord[i].ft >> cord[i].sd;
			if (!mp[cord[i]])
				mp[cord[i]] = ++id;
			rep(j,0,i)
				uf.addEdge(mp[cord[i]], mp[cord[j]], Dist(i, j));
		}
		auto ret = uf.Kruskal();
		cout << "Case #" << tt + 1 << ": ";
		int states = 1;
		double road = 0, rail = 0;
		m = m * m;
		for (auto it : ret) {
			if (it.weight > m) {
				states++, rail += sqrt(it.weight);
			} else {
				road += sqrt(it.weight);
			}
		}
		cout << states << " " << round(road) << " " << round(rail) << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
