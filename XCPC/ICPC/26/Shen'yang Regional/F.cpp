#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
void solve() {
    ll n, d;
    cin >> n >> d;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    bool flag = false;
    rep(i, 0, n - 1) {
        auto pos = ranges::lower_bound(a, a[i] + d) - a.begin();
        if (pos == n) continue;
        if (a[pos] - a[i] < 2 * d) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << 1 << endl;
        return;
    }
    bool flag2 = false;
    rep(i, 0, n - 1) {
        auto pos = ranges::lower_bound(a, a[i] + 2 * d) - a.begin();
        if (pos == n) continue;
        if (a[pos] - a[i] < 3 * d) {
            flag2 = true;
            break;
        }
    }
    if (!flag2) {
        cout << 2 << endl;
        return;
    }
    vl l(n, -1), diff(n + 1);
    rep(i, 0, n - 1) {
        auto pos = ranges::lower_bound(a, a[i] + d) - a.begin();
        auto pos2 = ranges::lower_bound(a, a[i] + 2 * d) - a.begin();
        if (pos == pos2) continue;
        l[i] = pos, diff[pos]++, diff[pos2 - 1]--;
    }
    vl id(n + 1);
    ll cnt = 1, cur = 0;
    rep(i, 0, n - 2) {
        cur += diff[i];
        if (cur)
            id[i + 1] = id[i];
        else
            id[i + 1] = cnt++;
    }
    vvl ma(cnt);
    rep(i, 0, n - 1) {
        if (l[i] == -1) continue;
        if (id[i] == id[l[i]]) {
            cout << 3 << endl;
            return;
        }
        ma[id[i]].push_back(id[l[i]]);
        ma[id[l[i]]].push_back(id[i]);
    }
    vl col(cnt);
    auto dfs = [&](this auto&& dfs, int x, int c) -> bool {
        col[x] = c;
        for (auto& p : ma[x]) {
            if (col[p] == c || (col[p] == 0 && !dfs(p, 3 - c))) return false;
        }
        return true;
    };
    rep(i, 0, cnt - 1) {
        if (col[i]) continue;
        if (!dfs(i, 1)) {
            cout << 3 << endl;
            return;
        }
    }
    cout << 2 << endl;
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
