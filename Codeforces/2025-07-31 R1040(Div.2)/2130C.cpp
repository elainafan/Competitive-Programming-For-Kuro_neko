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
const ll MAXN = 6e3 + 5;
void solve() {
    ll n, x, y;
    cin >> n;
    vl res;
    vector<vector<pll>> ma(MAXN);
    rep(i, 0, n - 1) {
        cin >> x >> y;
        ma[x].emplace_back(y, i);
        ma[y].emplace_back(x, i);
    }
    vl vis(MAXN);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        vis[x] = 1;
        for (auto& [y, id] : ma[x]) {
            if (vis[y] || y == pa) continue;
            res.push_back(id);
            dfs(y, x);
        }
        return;
    };
    rep(i, 1, MAXN - 1) {
        if (!vis[i]) dfs(i, -1);
    }
    cout << sz(res) << endl;
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
