#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>> a
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi p(n);
    vi tem;
    rep(i, 0, n - 1) {
        if (s[i] == '0') {
            if (i == 0) {
                if (s[1] == '1') {
                    cout << "NO" << endl;
                    return;
                }
            } else if (i == n - 1) {
                if (s[n - 2] == '1') {
                    cout << "NO" << endl;
                    return;
                }
            } else {
                if (s[i - 1] == '1' && s[i + 1] == '1') {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    rep(i, 0, n - 1) {
        int j = i;
        while (s[j] == s[i] && j <= n - 1) j++;
        int idx = j - 1;
        if (s[i] == '0') {
            int len = j - i;
            rep(j, 0, len - 1) p[i + j] = i + len - j;
        } else {
            rep(j, i, idx) p[j] = j + 1;
        }
        i = idx;
    }
    rep(i, 0, n - 1) cout << p[i] << ' ';
    cout << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
