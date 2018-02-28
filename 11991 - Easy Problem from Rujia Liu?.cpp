#include <bits/stdc++.h>
using namespace std;
const int oo = (int) 10e5 + 1;
int m, n, k, v;
vector<int> arr[oo];
int main() {
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++)
			cin >> v, arr[v].push_back(i);

		for (int i = 0; i < m; i++) {
			cin >> k >> v;
			if ((int) arr[v].size() >= k)
				cout << arr[v][k - 1] << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}
