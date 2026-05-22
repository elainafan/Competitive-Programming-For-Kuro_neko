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
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi sorted;
    rep(i, 0, n - 1) cin >> a[i], sorted.push_back(a[i]);
    rep(i, 0, n - 1) cin >> b[i], sorted.push_back(b[i]);
    ranges::sort(sorted);
    sorted.erase(unique(all(sorted)), sorted.end());
    int cnt = sz(sorted);
    vi tot(cnt);
    vi cnta(n), cntb(n);
    vi res;
    vector<vector<pii>> ma3(cnt);
    rep(i, 0, n - 1) {
        cnta[i] = ranges::lower_bound(sorted, a[i]) - sorted.begin();
        cntb[i] = ranges::lower_bound(sorted, b[i]) - sorted.begin();
        tot[cnta[i]]++, tot[cntb[i]]++;
        ma3[cnta[i]].emplace_back(cntb[i], i);
        ma3[cntb[i]].emplace_back(cnta[i], i);
    }
    rep(i, 0, cnt - 1) {
        if (tot[i] % 2) {
            cout << -1 << endl;
            return;
        }
    }
    vector<bool> vis(n, false);
    vi head(cnt);
    auto dfs = [&](this auto&& dfs, int x) -> void {
        for (int& i = head[x]; i < sz(ma3[x]);) {
            auto [to, id] = ma3[x][i++];
            if (vis[id]) continue;
            vis[id] = true;
            if (cnta[id] != x) res.push_back(id);
            dfs(to);
        }
    };
    rep(i, 0, cnt - 1) { dfs(i); }
    cout << sz(res) << endl;
    rep(i, 0, sz(res) - 1) cout << res[i] + 1 << ' ';
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
