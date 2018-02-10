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
typedef unsigned long long ll;
typedef unsigned long ul;
const int MX = 10e5 + 1;
void Solution() {
	string x, y;
	set<string> xa;
	while (cin >> x) {
		y = "";
		rep(i,0,sz(x))
		{
			x[i] = tolower(x[i]);
			if (x[i] - 'a' >= 0 and x[i] - 'a' <= 25)
				y += x[i];
			else if (sz(y) > 0)
				xa.insert(y), y = "";
		}
		if (y != "")
			xa.insert(y);
	}
	for (auto it : xa)
		cout << it << endl;
}
int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	Solution();
	return 0;
}
