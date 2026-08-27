#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, m;
    cin >> n;
    vl pa(n);
    vvl ma(n);
    rep(i, 1, n - 1) {
        cin >> pa[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
        ma[i].push_back(pa[i]);
    }
    cin >> m;
    vl a(m);
    rep(i, 0, m - 1) cin >> a[i], a[i]--;
    set<ll> s;
    for (auto& p : a) s.insert(p);
    vl res;
    vvl dp(n, vl(2, LLONG_MAX / 3));
    vl tem(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        ll mixx = LLONG_MAX / 3, idx = -1;
        ll tot = 0;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            tot += min(dp[p][0], dp[p][1] + 1);
            if (dp[p][1] != LLONG_MAX / 3 && dp[p][1] - min(dp[p][0], dp[p][1] + 1) < mixx) {
                mixx = dp[p][1] - min(dp[p][0], dp[p][1] + 1);
                idx = p;
            }
        }
        if (s.count(x)) {
            dp[x][0] = LLONG_MAX / 3, dp[x][1] = tot;
        } else {
            dp[x][0] = tot;
            if (idx != -1) dp[x][1] = tot + mixx, tem[x] = idx;
        }
        return;
    };
    dfs(0, -1);
    auto dfs2 = [&](this auto&& dfs2, int x, int pa, int r) -> void {
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            if (r == 1 && !s.count(x) && p == tem[x]) {
                dfs2(p, x, 1);
                continue;
            }
            if (dp[p][0] <= dp[p][1] + 1)
                dfs2(p, x, 0);
            else {
                res.push_back(p);
                dfs2(p, x, 1);
            }
        }
        return;
    };
    dfs2(0, -1, dp[0][0] > dp[0][1]);
    cout << sz(res) << ' ';
    for (auto& p : res) cout << p + 1 << ' ';
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
