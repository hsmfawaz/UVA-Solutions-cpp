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
vi v(MX);
void MergeWithCountInversions(int p, int q, int r, int& cnt) {
	int n1 = q - p, n2 = r - q;
	vector<int> L, R;
	for (int i = 0; i < n1; ++i)
		L.push_back(v[p + i]);
	for (int i = 0; i < n2; ++i)
		R.push_back(v[q + i]);
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);

	int i = 0, j = 0;
	for (int k = p; k < r; ++k) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			i++;
		} else {
			v[k] = R[j];
			j++;
			cnt += n1 - i;
		}
	}
}

void MergeSort(int p, int r, int& cnt) {
	if (p >= r - 1)
		return;
	int q = (p + r) >> 1;
	MergeSort(p, q, cnt);
	MergeSort(q, r, cnt);
	MergeWithCountInversions(p, q, r, cnt);
}

void Solution() {
	int n;
	while (scanf("%d", &n), n) {
		v.resize(n);
		rep(i,0,n)
			scanf("%d", &v[i]);
		int ct = 0;
		MergeSort(0, n, ct);
		printf("%s\n", (ct & 1 ? "Marcelo" : "Carlos"));
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
