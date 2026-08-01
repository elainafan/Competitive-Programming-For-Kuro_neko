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
    ll n, x, y;
    cin >> n;
    vvl ma(n);
    vl deg(n);
    rep(i, 0, n - 2) {
        cin >> x >> y;
        x--, y--;
        ma[x].push_back(y);
        ma[y].push_back(x);
        deg[x]++, deg[y]++;
    }
    ll ans = 0;
    rep(i, 0, n - 1) {
        for (auto& p : ma[i]) {
            if (deg[i] % 2 == 1 && deg[p] % 2 == 1) ans++;
        }
    }
    ans /= 2;
    vector<bool> vis(n, false);
    rep(i, 0, n - 1) {
        if (deg[i] % 2 == 1) continue;
        if (vis[i]) continue;
        queue<ll> q;
        q.push(i);
        ll tem = 0;
        ll tem2 = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (vis[node]) continue;
            vis[node] = true;
            for (auto& p : ma[node]) {
                if (deg[p] % 2 == 1)
                    tem++;
                else {
                    if (vis[p]) continue;
                    tem2++;
                    q.push(p);
                }
            }
        }
        ans += tem * (tem - 1) / 2;
    }
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
