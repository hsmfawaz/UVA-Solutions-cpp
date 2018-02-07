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
	unsigned int x;
	while (cin >> x, x) {
		unsigned int a = 0, b = 0, i = 1;
		bool turn = true;
		while (x) {
			if (x & 1) {
				a += turn ? i : 0;
				b += !turn ? i : 0;
				turn = !turn;
			}
			x /= 2;
			i *= 2;
		}
		cout << a << " " << b << endl;
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
