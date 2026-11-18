#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
void solve() {
    ll n, m, a, b, c, d, x, y;
    cin >> n >> m;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    vvl ma(n);
    set<pll> edges;
    rep(_, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
        edges.insert(make_pair(min(x - 1, y - 1), max(x - 1, y - 1)));
    }
    ll ans = INF;
    auto bfs = [&](ll st) -> vl {
        vl dis(n, -1);
        queue<ll> q;
        q.emplace(st);
        dis[st] = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto& p : ma[node]) {
                if (dis[p] == -1) {
                    dis[p] = dis[node] + 1;
                    q.emplace(p);
                }
            }
        }
        return dis;
    };
    auto dis1 = bfs(b), dis2 = bfs(d);
    if (a == c) ans = min(ans, dis1[d]);
    if (edges.count(make_pair(min(a, c), max(a, c)))) ans = min(ans, dis1[c] + 1 + dis2[a]);
    vvl cnt(3);
    for (auto& p : ma[a]) {
        cnt[dis1[p] - dis1[a] + 1].push_back(p);
    }
    auto bfs2 = [&](vl& st) -> vl {
        vl dis(n, -1);
        queue<ll> q;
        for (auto& p : st) dis[p] = 0, q.emplace(p);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto& p : ma[node]) {
                if (dis[p] == -1) {
                    dis[p] = dis[node] + 1;
                    q.emplace(p);
                }
            }
        }
        return dis;
    };
    rep(i, 0, 2) {
        if (cnt[i].empty()) continue;
        auto dis3 = bfs2(cnt[i]);
        for (auto& p : ma[c]) ans = min(ans, dis1[a] + 3 * dis3[p] + dis2[p] + i + 3);
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
