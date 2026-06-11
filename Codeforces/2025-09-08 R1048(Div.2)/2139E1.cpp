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
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, k;
    cin >> n >> k;
    vl pa(n);
    vvl ma(n);
    rep(i, 1, n - 1) {
        cin >> pa[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
        ma[i].push_back(pa[i]);
    }
    vl cnt(n + 1);
    ll mixx = LLONG_MAX;
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
        cnt[d]++;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x, d + 1);
        }
        if (sz(ma[x]) == 1 && x != 0) mixx = min(mixx, 1LL * d);
        return;
    };
    dfs(0, -1, 0);
    ll tot = 0;
    rep(i, 0, mixx) tot += cnt[i];
    vb dp(tot + 1, false);
    dp[0] = true;
    rep(i, 0, mixx) { frep(j, tot, cnt[i]) dp[j] = dp[j] | dp[j - cnt[i]]; }
    rep(i, 0, tot) {
        if (!dp[i]) continue;
        if (i <= k && tot - i <= n - k) {
            cout << mixx + 1 << endl;
            return;
        }
    }
    cout << mixx << endl;
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
