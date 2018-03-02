#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x) memset(x,0,sizeof x)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 1025;
map<char, vector<char> > mp;
map<char, bool> vis;
void dfs(char x) {
	vis[x] = true;
	rep(i,0,sz(mp[x]))
		if (!vis[mp[x][i]])
			dfs(mp[x][i]);
}
void solution() {
	int t;
	cin >> t;
	rep(tt,0,t)
	{
		mp.clear();
		vis.clear();
		string s;
		while (cin >> s, s[0] != '*') {
			mp[s[1]].push_back(s[3]);
			mp[s[3]].push_back(s[1]);
		}
		cin >> s;
		int acron = 0, tree = 0;
		rep(i,0,sz(s))
			if (s[i] != ',')
				if (mp.find(s[i]) == mp.end())
					acron++;
		for (auto it : mp) {
			if (!vis[it.ft])
				dfs(it.ft), tree++;
		}
		cout << "There are " << tree << " tree(s) and " << acron
				<< " acorn(s).\n";
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
