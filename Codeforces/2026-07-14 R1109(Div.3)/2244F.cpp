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
    vl pa(n);
    vvl ma(n);
    rep(i, 1, n - 1) {
        cin >> pa[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
        ma[i].push_back(pa[i]);
    }
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    bool flag = true;
    auto dfs = [&](this auto&& dfs, int x, int pa) -> pll {
        if (a[x] != 0) return {a[x], a[x]};
        vector<pll> tem;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            auto tem2 = dfs(p, x);
            tem.push_back(tem2);
        }
        int idx = -1;
        ll mixx = LLONG_MAX;
        int m = sz(tem);
        rep(i, 0, m - 1) {
            if (tem[i].first < mixx) {
                idx = i, mixx = tem[i].first;
            }
        }
        rep(i, 1, m - 1) {
            if (tem[(idx + i) % m].first == tem[(idx + i - 1 + m) % m].second + 1) continue;
            flag = false;
        }
        ll maxx = LLONG_MIN;
        rep(i, 0, m - 1) { maxx = max(maxx, tem[i].second); }
        return {mixx, maxx};
    };
    dfs(0, -1);
    cout << (flag ? "YES" : "NO") << endl;
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
