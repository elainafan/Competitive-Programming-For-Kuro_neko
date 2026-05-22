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
    int n, m;
    cin >> n >> m;
    vvl ma(n, vl(m));
    rep(i, 0, n - 1) { rep(j, 0, m - 1) cin >> ma[i][j]; }
    vvl dp(n, vl(m, LLONG_MIN / 2));
    dp[0][0] = ma[0][0];
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            if (i == 0 && j == 0) continue;
            int ax = i - 1, ay = j;
            int bx = i, by = j - 1;
            if (ax >= 0 && ax <= n - 1 && ay >= 0 && ay <= m - 1) {
                dp[i][j] = max(dp[i][j], dp[ax][ay] + 1LL * ma[i][j]);
            }
            if (bx >= 0 && bx <= n - 1 && by >= 0 && by <= m - 1) {
                dp[i][j] = max(dp[i][j], dp[bx][by] + 1LL * ma[i][j]);
            }
        }
    }
    ll ans = dp[n - 1][m - 1];
    vvl fdp(n, vl(m, LLONG_MIN / 2));
    fdp[n - 1][m - 1] = ma[n - 1][m - 1];
    frep(i, n - 1, 0) {
        frep(j, m - 1, 0) {
            if (i == n - 1 && j == m - 1) continue;
            int ax = i + 1, ay = j;
            int bx = i, by = j + 1;
            if (ax >= 0 && ax <= n - 1 && ay >= 0 && ay <= m - 1) {
                fdp[i][j] = max(fdp[i][j], fdp[ax][ay] + ma[i][j]);
            }
            if (bx >= 0 && bx <= n - 1 && by >= 0 && by <= m - 1) {
                fdp[i][j] = max(fdp[i][j], fdp[bx][by] + ma[i][j]);
            }
        }
    }
    vvl pre1(n, vl(m, LLONG_MIN / 2));
    vvl pre2(n, vl(m, LLONG_MIN / 2));
    frep(i, n - 1, 0) {
        rep(j, 0, m - 1) {
            if (i != n - 1) pre1[i][j] = max(pre1[i][j], pre1[i + 1][j]);
            if (j != 0) pre1[i][j] = max(pre1[i][j], pre1[i][j - 1]);
            pre1[i][j] = max(pre1[i][j], dp[i][j] + fdp[i][j] - ma[i][j]);
        }
    }
    rep(i, 0, n - 1) {
        frep(j, m - 1, 0) {
            if (i != 0) pre2[i][j] = max(pre2[i][j], pre2[i - 1][j]);
            if (j != m - 1) pre2[i][j] = max(pre2[i][j], pre2[i][j + 1]);
            pre2[i][j] = max(pre2[i][j], dp[i][j] + fdp[i][j] - ma[i][j]);
        }
    }
    int x = n - 1, y = m - 1;
    vector<pii> path;
    path.emplace_back(x, y);
    while (!(x == 0 && y == 0)) {
        if (x == 0 && y != 0)
            y--;
        else if (x != 0 && y == 0)
            x--;
        else {
            if (dp[x - 1][y] > dp[x][y - 1])
                x--;
            else
                y--;
        }
        path.emplace_back(x, y);
    }
    rep(i, 0, sz(path) - 1) {
        auto& [x, y] = path[i];
        ll res = LLONG_MIN;
        res = max(res, dp[n - 1][m - 1] - 2 * ma[x][y]);
        if (x != n - 1 && y != 0) res = max(res, pre1[x + 1][y - 1]);
        if (x != 0 && y != m - 1) res = max(res, pre2[x - 1][y + 1]);
        ans = min(ans, res);
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
