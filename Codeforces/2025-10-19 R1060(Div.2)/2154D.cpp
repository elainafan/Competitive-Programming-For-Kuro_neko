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
    vvl ma(n);
    vl deg(n);
    rep(i, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
        deg[x - 1]++, deg[y - 1]++;
    }
    queue<ll> q;
    vl dis(n, -1);
    dis[0] = 0;
    q.push(0);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto& p : ma[node]) {
            if (dis[p] == -1) {
                dis[p] = dis[node] + 1;
                q.push(p);
            }
        }
    }
    queue<ll> qq[2];
    rep(i, 0, n - 1) {
        if (i != n - 1 && deg[i] == 1) qq[dis[i] % 2].push(i);
    }
    vector<pll> res;
    vl vis(n);
    ll cur = 0, cnt = 0;
    while (cnt < n - 1) {
        res.emplace_back(1, -1);
        cur ^= 1;
        if (qq[cur ^ 1].empty()) {
            res.emplace_back(1, -1);
            cur ^= 1;
        }
        auto node = qq[cur ^ 1].front();
        qq[cur ^ 1].pop();
        res.emplace_back(2, node + 1);
        vis[node] = 1;
        cnt++;
        for (auto& p : ma[node]) {
            if (vis[p]) continue;
            if (p != n - 1 && --deg[p] == 1) qq[dis[p] % 2].push(p);
        }
        deg[node] = 0;
    }
    cout << sz(res) << endl;
    for (auto& p : res) {
        if (p.first == 1)
            cout << 1 << endl;
        else
            cout << 2 << ' ' << p.second << endl;
    }
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
