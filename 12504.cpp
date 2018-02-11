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
int z[100000];

void Solution() {
	int n;
	cin >> n;
	while (n--) {
		string x, y;
		cin >> x >> y;
		map<string, string> xa, xa2;

		string key = "", val = "";
		rep(i,1,sz(x))
		{
			if (isalpha(x[i])) {
				key += x[i];
			} else if (isdigit(x[i]))
				val += x[i];
			else if (x[i] == '}' || x[i] == ',') {
				xa[key] = val;
				val = key = "";
			}
		}
		key = "", val = "";
		rep(i,1,sz(y))
		{
			if (isalpha(y[i])) {
				key += y[i];
			} else if (isdigit(y[i]))
				val += y[i];
			else if (y[i] == '}' || y[i] == ',') {
				xa2[key] = val;
				val = key = "";
			}
		}
		vector<string> add, change;
		map<string, int> deleted;
		for (auto it : xa) {
			if (sz(xa2[it.first]) == 0)
				deleted[it.first] = 1;
		}
		for (auto it : xa2) {
			if (sz(xa[it.first]) == 0)
				add.push_back(it.first);
			else if (xa[it.first] != it.second and deleted[it.first] == 0)
				change.push_back(it.first);
		}

		if (xa == xa2) {
			cout << "No changes\n";
		} else {
			if (sz(add) > 0) {
				string t = "";
				rep(i,0,sz(add))
					if (add[i] != "")
						t += add[i] + ',';
				t[sz(t) - 1] = '\n';
				cout << (sz(t) > 0 and t != "\n" ? "+" + t : "");
			}
			if (sz(deleted) > 0) {

				string t = "";
				for (auto it : deleted)
					if (it.second == 1)
						t += it.first + ",";
				t[sz(t) - 1] = '\n';
				cout << (sz(t) > 0 and t != "\n" ? "-" + t : "");
			}
			if (sz(change) > 0) {
				string t = "";
				rep(i,0,sz(change))
					if (change[i] != "")
						t += change[i] + ',';
				t[sz(t) - 1] = '\n';
				cout << (sz(t) > 0 and t != "\n" ? "*" + t : "");
			}
		}
		cout << endl;
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
