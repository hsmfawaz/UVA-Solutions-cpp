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
bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}
void Solution() {
	int t;
	cin >> t;
	rep(tt,0,t)
	{
		int n, s, ss;
		cin >> n;
		vector<pair<double, int> > xa;
		rep(i,0,n)
			cin >> s >> ss, xa.push_back( { s / (double) ss, i + 1 });
		sort(all(xa), cmp);
		rep(i,0,n)
			cout << xa[i].second << (i + 1 != n ? " " : "");
		cout << endl << (tt + 1 != t ? "\n" : "");
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
