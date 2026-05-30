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
void solve() {
    ll n, k, x, y;
    cin >> n >> k;
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vl siz(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        ll tem = 1;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            tem += siz[p];
        }
        siz[x] = tem;
        return;
    };
    dfs(0, -1);
    vl res(n);
    rep(i, 0, n - 1) res[0] += (siz[i] >= k);
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        for (int& p : ma[x]) {
            if (p == pa) continue;
            res[p] = res[x];
            if (siz[p] < k) res[p]++;
            if (n - siz[p] < k) res[p]--;
            dfs2(p, x);
        }
    };
    dfs2(0, -1);
    ll ans = 0;
    rep(i, 0, n - 1) ans += res[i];
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
