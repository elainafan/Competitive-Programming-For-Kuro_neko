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
    ll n, m, x, y;
    cin >> n >> m;
    vl pa(n);
    rep(i, 0, n - 2) pa[i] = i + 1;
    pa[n - 1] = n - 1;
    rep(i, 0, m - 1) {
        cin >> x >> y;
        x--, y--;
        pa[x] = max(pa[x], y);
    }
    vvl ma(n);
    rep(i, 0, n - 2) { ma[pa[i]].push_back(i); }
    vl dep(n), siz(n);
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
        dep[x] = d;
        ll tem = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x, d + 1);
            tem += siz[p];
        }
        siz[x] = tem;
        return;
    };
    dfs(n - 1, -1, 0);
    ll ans = 0;
    vl pre(n);
    rep(i, 0, n - 1) pre[dep[i]]++;
    frep(i, n - 2, 0) pre[i] += pre[i + 1];
    vl sum(n);
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> pair<map<ll, ll>, ll> {
        map<ll, ll> ma2;
        ma2[dep[x]]++;
        ll tem = pre[dep[x]];
        ll tem2 = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            auto [ma3, tem3] = dfs2(p, x);
            tem += sum[p];
            if (sz(ma3) > sz(ma2)) {
                swap(ma2, ma3);
                swap(tem2, tem3);
            }
            for (auto& [a, b] : ma3) {
                tem2 -= ma2[a] * ma2[a];
                ma2[a] += b;
                tem2 += ma2[a] * ma2[a];
            }
        }
        sum[x] = tem;
        if (x != n - 1) {
            ans += (sum[x] - (siz[x] * siz[x] + tem2) / 2);
        }
        return {move(ma2), tem2};
    };
    dfs2(n - 1, -1);
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
