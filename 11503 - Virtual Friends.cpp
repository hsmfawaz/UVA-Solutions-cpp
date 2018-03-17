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
const int oo = 2e6 + 5, OO = 10e8;
int t, n;
struct UnionFind {
	vector<int> rank, parent;
	int number;
	UnionFind(int n) {
		number = n;
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

	int link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		rank[y] += rank[x];
		return y;
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			cout << rank[link(x, y)] << endl;
		} else
			cout << rank[x] << endl;
		return x != y;
	}
};

void solution() {
	cin >> t;
	while (t--) {
		cin >> n;
		map<string, int> ids;
		string x, y;
		int id = 0;
		UnionFind uf(200001);
		rep(i,0,n)
		{
			cin >> x >> y;
			if (ids.find(x) == ids.end())
				ids[x] = id++;
			if (ids.find(y) == ids.end())
				ids[y] = id++;
			uf.union_sets(ids[x], ids[y]);
		}
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
