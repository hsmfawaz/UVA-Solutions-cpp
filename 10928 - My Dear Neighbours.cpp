#include <bits/stdc++.h>
using namespace std;
const int oo = 1001;
int n, p, t;
bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
	if (b.first.size() == 0 || a.first.size() == 0)
		return false;
	else if (a.first.size() < b.first.size())
		return a.first.size() < b.first.size();
	else if (a.first.size() == b.first.size())
		return a.second < b.second;
	return false;
}
int main() {
	cin >> n;
	for (int t = 0; t < n; t++) {
		cin >> p;
		vector<pair<vector<int>, int> > arr(p);
		cin.ignore();
		for (int i = 0; i < p; i++) {
			arr[i].second = i + 1;
			string x, cum = "";
			getline(cin, x);
			for (int j = 0; j < (int) x.size(); j++) {
				if (x[j] != ' ')
					cum += x[j];
				if (x[j] == ' ' || j + 1 == (int) x.size())
					arr[i].first.push_back(stoi(cum)), cum = "";
			}
		}
		sort(arr.begin(), arr.end(), cmp);
		int sm = arr[0].first.size();
		for (int j = 0; j < p; j++) {
			if ((int) arr[j].first.size() == sm)
				cout << (j != 0 ? " " : "") << arr[j].second;
			else
				break;
		}
		cout << endl;
	}
	return 0;
}
