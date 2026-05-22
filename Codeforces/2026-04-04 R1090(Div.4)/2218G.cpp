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
const int MOD = 676767677;
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    if (n == 1) {
        cout << ((a[0] == 0) ? 1 : 0) << endl;
        return;
    }
    rep(i, 0, n - 1) {
        if (a[i] == 0) continue;
        if (i == 0 && a[i] <= a[i + 1]) {
            cout << 0 << endl;
            return;
        } else if (i == n - 1 && a[i] <= a[i - 1]) {
            cout << 0 << endl;
            return;
        } else if (a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
            cout << 0 << endl;
            return;
        }
    }
    vi pre(m + 1);
    ll res = 1;
    rep(i, 0, n - 1) { pre[a[i]]++; }
    rep(i, 1, m) pre[i] += pre[i - 1];
    rep(i, 0, n - 1) {
        if (a[i] == 0) continue;
        if (i == 0) {
            if (a[1] < a[0] - 1) {
                res = res * (pre[a[0] - 1] - (a[0] == 1 ? 0 : pre[a[0] - 2])) % MOD;
            } else
                res = res * pre[a[0] - 1] % MOD;
        } else if (i == n - 1) {
            if (a[n - 2] < a[n - 1] - 1) {
                res = res * (pre[a[n - 1] - 1] - (a[n - 1] == 1 ? 0 : pre[a[n - 1] - 2])) % MOD;
            } else
                res = res * pre[a[n - 1] - 1] % MOD;
        } else {
            int tem = min(a[i - 1], a[i + 1]);
            if (tem < a[i] - 1) {
                res = res * (pre[a[i] - 1] - (a[i] == 1 ? 0 : pre[a[i] - 2])) % MOD;
            } else
                res = res * pre[a[i] - 1] % MOD;
        }
    }
    cout << res << endl;
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
