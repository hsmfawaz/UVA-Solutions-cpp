#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef unsigned long ul;
const int oo = 150123;
int play(ul a, ul b) {
	if (!b) return 0;
	if (a / b > 1) return 1;
	return play(b, a - b) + 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ul a, b;
	while (cin >> a >> b, a) {
		if (a < b)
			swap(a, b);
		int ct = play(a, b);
		cout << (ct & 1 ? "Stan wins" : "Ollie wins") << endl;
	}
	return 0;
}
