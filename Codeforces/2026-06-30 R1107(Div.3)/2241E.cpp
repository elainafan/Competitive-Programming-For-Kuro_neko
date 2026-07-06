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
    ll n, x, y;
    cin >> n;
    vl a(n);
    vvl ma(n);
    vl vis(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) {
        ll tem = sqrt(a[i]);
        if (tem * tem == a[i]) vis[i] = 1;
    }
    rep(i, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vl siz(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        ll tem = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            tem += siz[p];
        }
        siz[x] = tem;
        return;
    };
    dfs(0, -1);
    ll ans = 0;
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (auto& p : ma[x]) {
            if (p == pa) {
                cnt2 += cnt1 * (n - siz[x]);
                cnt1 += cnt0 * (n - siz[x]);
                cnt0 += n - siz[x];
            } else {
                cnt2 += cnt1 * siz[p];
                cnt1 += cnt0 * siz[p];
                cnt0 += siz[p];
            }
        }
        ans += (vis[x] ? cnt1 + cnt2 : 0);
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs2(p, x);
        }
        return;
    };
    dfs2(0, -1);
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
