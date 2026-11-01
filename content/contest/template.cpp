#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1}; // URDL, UR DR DL UL
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
template<class T> void print(const vector<T> &v) { for (auto &x : v) cout << x << ' '; cout << endl; }
template<class... T> void print(const T&... x) { ((cout << x << ' '), ...); cout << endl; }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
}
