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
    vector<pii> ma(n + 1);
    rep(i, 1, n) cin >> ma[i].first >> ma[i].second;
    vector<pll> siz(n + 1);
    vl res(n + 1);
    auto dfs = [&](this auto&& dfs, int x) -> int {
        if (ma[x].first != 0) siz[x].first = dfs(ma[x].first);
        if (ma[x].second != 0) siz[x].second = dfs(ma[x].second);
        return siz[x].first + siz[x].second + 1;
    };
    dfs(1);
    res[1] = (2LL * siz[1].first + 2LL * siz[1].second + 1) % MOD;
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        if (x != 1) {
            res[x] = (res[pa] + 2LL * siz[x].first + 2LL * siz[x].second + 1) % MOD;
        }
        if (ma[x].first) dfs2(ma[x].first, x);
        if (ma[x].second) dfs2(ma[x].second, x);
        return;
    };
    dfs2(1, -1);
    rep(i, 1, n) cout << res[i] << ' ';
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
