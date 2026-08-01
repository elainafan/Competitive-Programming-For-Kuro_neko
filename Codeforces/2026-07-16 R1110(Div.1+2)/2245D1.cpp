#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
    ll n, m, x, y, op;
    cin >> n >> m;
    vector<vector<pll>> ma(n);
    vl deg(n);
    vl deg2(n);
    rep(i, 0, m - 1) {
        cin >> op >> x >> y;
        x--, y--;
        if (x == y) {
            ma[x].emplace_back(x, op);
            deg[x]++;
            if (op == 1) deg2[x]++;
            continue;
        }
        ma[x].emplace_back(y, op);
        ma[y].emplace_back(x, op);
        deg[x]++, deg[y]++;
        if (op == 1) deg2[x]++, deg2[y]++;
    }
    vl res(n, LLONG_MAX / 3);
    vector<bool> vis(n, false);
    queue<ll> q;
    rep(i, 0, n - 1) {
        if (deg[i] == deg2[i] || (deg2[i] == 0)) q.push(i);
    }
    ll cnt = n;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (vis[node]) continue;
        vis[node] = true;
        res[node] = (deg[node] == deg2[node] ? cnt : -cnt);
        cnt--;
        for (auto& [x, y] : ma[node]) {
            if (vis[x]) continue;
            ll tem = (y == 1 ? 1 : 0);
            deg[x]--, deg2[x] -= tem;
            if (deg[x] == deg2[x] || (deg2[x] == 0)) {
                q.push(x);
            }
        }
    }
    rep(i, 0, n - 1) {
        if (res[i] == LLONG_MAX / 3) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
