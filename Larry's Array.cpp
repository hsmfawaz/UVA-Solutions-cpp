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
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int num[n];
		rep(i,0,n)
			cin >> num[i];
		bool valid = true;
		rep(i,0,n)
			rep(j,i+1,n)
				valid ^= num[i] > num[j];
		cout << (valid ? "YES" : "NO") << endl;
	}
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
