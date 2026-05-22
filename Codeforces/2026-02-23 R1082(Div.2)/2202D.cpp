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
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    if (k > 2 * n - 1 || k < n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (k == n) {
        rep(i, 1, n) cout << i << ' ' << i << ' ';
        cout << endl;
        return;
    }
    int tem = k - n;
    int res = k + 1 - n;
    cout << "1 2 ";
    rep(i, 3, res) cout << i << ' ' << i - 2 << ' ';
    cout << res - 1 << ' ' << res << ' ';
    rep(i, res + 1, n) cout << i << ' ' << i << ' ';
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
