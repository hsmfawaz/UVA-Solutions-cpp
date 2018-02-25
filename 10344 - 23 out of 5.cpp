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
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long ul;
const int oo = 1025;
int a[5];
bool res = false;
void run(int i, int last) {
	if (i == 5) if (!res) res = last == 23;

	if (res || i == 5)  return;

	run(i + 1, last + a[i]);
	run(i + 1, last - a[i]);
	run(i + 1, last * a[i]);
}
void solution() {
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4], a[0]) {
		res = false;
		sort(a, a + 5);
		do run(1, a[0]);
		while (next_permutation(a, a + 5) and !res);
		cout << (!res ? "Impossible" : "Possible") << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
