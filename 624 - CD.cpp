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
typedef unsigned long long ull;
typedef unsigned long ul;
const int oo = 21;
int y, arr[oo];
ull x, res;
bool taken[oo], final[oo];
void bruteforce(int pos) {
	if (pos >= y) {
		ull sum = 0;
		rep(i,0,y)
			sum += taken[i] ? arr[i] : 0;
		if (sum <= x and sum > res) {
			res = sum;
			rep(i,0,y)
				final[i] = taken[i];
		}
		return;
	}

	taken[pos] = true;
	bruteforce(pos + 1);
	taken[pos] = false;
	bruteforce(pos + 1);
}
void solution() {
	while (cin >> x >> y) {
		rep(i,0,y)
			cin >> arr[i];
		clr(taken), clr(final), res = 0;
		bruteforce(0);
		rep(i,0,y)
			if (final[i])
				cout << arr[i] << " ";
		cout << "sum:" << res << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
