#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
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
#define endl '\n'
using namespace std;
void solve() {
    int n, x, y;
    cin >> n;
    vvi ma(n);
    vi deg(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    int tem = 0;
    vector<bool> vis(n, false);
    rep(i, 0, n - 1) {
        if (sz(ma[i]) == 1) vis[i] = true;
        tem += vis[i];
    }
    vi cnt(n);
    vi dep(n);
    vi tem2(n);
    vi tem3(n);
    ll ans = 0;
    int idx = -1;
    rep(i, 0, n - 1) {
        if (!vis[i]) {
            idx = i;
            break;
        }
    }
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> int {
        dep[x] = d;
        if (vis[x]) {
            tem2[x] = 1;
            ans++;
            return 1;
        }
        int tem3 = 0;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            int tem4 = dfs(p, x, d + 1);
            tem3 += tem4;
        }
        tem2[x] = tem3;
        if (x != idx && tem2[x] % 2 == 1) ans++;
        return tem3;
    };
    dfs(idx, -1, 0);
    if (tem % 2 == 0) {
        cout << ans << endl;
        return;
    }
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        if (x != idx) tem3[x] = tem3[pa] + tem2[x] % 2;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            dfs2(p, x);
        }
    };
    dfs2(idx, -1);
    ll ans2 = LLONG_MAX;
    rep(i, 0, n - 1) {
        if (vis[i]) ans2 = min(ans2, ans + dep[i] - 2 * tem3[i]);
    }
    cout << ans2 << endl;
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
