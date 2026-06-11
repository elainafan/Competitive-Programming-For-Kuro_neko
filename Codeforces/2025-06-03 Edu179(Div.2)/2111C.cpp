#include <bits/stdc++.h>
#define endl '\n'
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
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    bool flag = true;
    rep(i, 1, n - 1) {
        if (a[i] != a[i - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << endl;
        return;
    }
    ll ans = LLONG_MAX;
    vector<pll> tem;
    int las = 0;
    rep(i, 0, n - 1) {
        if ((i > 0 && a[i] != a[i - 1])) {
            tem.emplace_back(las, i - 1);
            las = i;
        }
        if (i == n - 1) tem.emplace_back(las, i);
    }
    for (auto& [x, y] : tem) {
        ans = min(ans, a[x] * x + a[y] * (n - 1 - y));
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
