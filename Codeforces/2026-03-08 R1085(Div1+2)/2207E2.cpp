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
const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 1;
    vi b(n);
    vector<bool> vis(n + 1, false);
    rep(i, 0, n - 1) {
        if (a[i] <= n) vis[a[i]] = true;
    }
    bool flag = true;
    rep(i, 0, n - 1) {
        if (i >= 1 && a[i] > a[i - 1]) {
            flag = false;
            break;
        }
        if (a[i] < n - i - 1 || a[i] > n) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << 0 << endl;
        return;
    }
    vi pre(n + 1);
    rep(i, 0, n) {
        if (vis[i])
            pre[i] = pre[i - 1];
        else
            pre[i] = pre[i - 1] + 1;
    }
    rep(i, 0, n - 1) {
        if (i >= 1 && a[i] == a[i - 1]) {
            ans *= 1LL * (a[i] - (n - i - 1));
            ans %= MOD;
        } else {
            ans *= 1LL * (i + 1);
            ans %= MOD;
        }
    }
    cout << ans << endl;
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
