#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define clr(x) memset(x,0,sizeof x)
#define pb push_back
#define fi first
#define sec second
typedef vector<int> vi;
typedef long long ll;
const int MX = 10e8 + 1;
int ct[500], qq[10001];
void Solution() {
	int x, y, z;
	cin >> x >> y;
	string tmp;
	map<string, int> mp;
	long long ct = 0;
	rep(i,0,x)
		cin >> tmp >> z, mp[tmp] = z;
	while (cin >> tmp) {
		ct += mp[tmp];
		if (tmp == ".") {
			cout << ct << endl;
			ct = 0;
		}
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
