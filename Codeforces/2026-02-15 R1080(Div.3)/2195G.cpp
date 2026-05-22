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
const ll INF = (1LL << 50);
void solve() {
    int n, q, v, k;
    cin >> n >> q;
    vector<pii> ma(n + 1);
    vi pa(n + 1);
    vl dp(n + 1);
    vvi up(n + 1, vi(20));
    vvl st(n + 1, vl(20, INF));
    pa[1] = 0;
    rep(i, 1, n) {
        cin >> ma[i].first >> ma[i].second;
        if (ma[i].first != 0) pa[ma[i].first] = i;
        if (ma[i].second != 0) pa[ma[i].second] = i;
    }
    vi path;
    vector<pll> siz(n + 1);
    vi pos(n + 1);
    auto dfs = [&](this auto&& dfs, int x) -> int {
        pos[x] = sz(path);
        path.push_back(x);
        if (ma[x].first != 0) {
            siz[x].first = dfs(ma[x].first);
            dp[x] += dp[ma[x].first] + 1;
            path.push_back(x);
            siz[x].second = dfs(ma[x].second);
            dp[x] += dp[ma[x].second] + 1;
            path.push_back(x);
        }
        dp[x]++;
        return siz[x].first + siz[x].second + 1;
    };
    dfs(1);
    path.push_back(0);
    rep(i, 0, n) up[i][0] = pa[i], st[i][0] = dp[i];
    rep(j, 0, 18) {
        rep(i, 1, n) {
            int mid = up[i][j];
            if (mid) {
                up[i][j + 1] = up[mid][j];
                if (st[i][j] != INF && st[mid][j] != INF) st[i][j + 1] = st[mid][j] + st[i][j];
            }
        }
    }
    rep(i, 0, q - 1) {
        cin >> v >> k;
        frep(j, 19, 0) {
            if (up[v][j] && st[v][j] <= k) {
                k -= st[v][j];
                v = up[v][j];
            }
        }
        cout << path[pos[v] + k] << ' ';
    }
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
