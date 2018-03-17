#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x,y) memset(x,(y),sizeof x)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 2e6 + 5, OO = 10e8;
int t, n;
struct node {
	int value;
	node *left;
	node *right;
};
struct node* newNode(int data) {
	struct node* node = (struct node*) malloc(sizeof(struct node));

	node->value = data;

	node->left = NULL;
	node->right = NULL;
	return (node);
}
bool cmp(pair<int, string> a, pair<int, string> b) {
	return sz(a.sd) < sz(b.sd);
}
void solution() {
	string x;
	vector<pair<int, string>> nodes;
	while (cin >> x) {
		if (x == "()") {
			sort(all(nodes), cmp);
			if (sz(nodes[0].sd) == 1) {
				node *root = newNode(nodes[0].ft);
				bool flag = true;
				for (int i = 1; i < sz(nodes) and flag; i++) {
					node *curroot = root;
					string path = nodes[i].sd;
					rep(j,1,sz(path))
					{
						if (path[j] == 'L') {
							if (j + 1 == sz(path)) {
								if (curroot->left == NULL)
									curroot->left = newNode(nodes[i].ft);
								else {
									flag = false;
									break;
								}
							}

							curroot = curroot->left;
						} else {
							if (j + 1 == sz(path)) {
								if (curroot->right == NULL)
									curroot->right = newNode(nodes[i].ft);
								else {
									flag = false;
									break;
								}
							}
							if (curroot->right == NULL and j + 1 == sz(path))
								curroot->right = newNode(nodes[i].ft);
							curroot = curroot->right;
						}
					}
				}
				if (!flag)
					cout << "not complete\n";
				else {
					queue<node> q;
					q.push(*root);
					while (!q.empty()) {
						node tp = q.front();
						q.pop();
						if (tp.left != NULL)
							q.push(*tp.left);
						if (tp.right != NULL)
							q.push(*tp.right);
						cout << (tp.value != root->value ? " " : "")
								<< tp.value;
					}
					cout << endl;
				}
			} else
				cout << "not complete\n";
			nodes.clear();
		} else {
			string tmp = x.substr(1, sz(x) - 2);
			stringstream p(tmp);
			p >> t >> tmp;
			nodes.pb( { t, tmp });
		}
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
