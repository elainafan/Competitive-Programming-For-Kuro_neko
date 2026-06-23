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
    ll n, s1, s2, m1, m2, x, y;
    cin >> n >> s1 >> s2;
    vvl ma1(n), ma2(n);
    s1--, s2--;
    cin >> m1;
    set<pll> s;
    vl vis(n);
    rep(i, 0, m1 - 1) {
        cin >> x >> y;
        ma1[x - 1].push_back(y - 1);
        ma1[y - 1].push_back(x - 1);
        s.insert(make_pair(min(x - 1, y - 1), max(x - 1, y - 1)));
    }
    cin >> m2;
    rep(i, 0, m2 - 1) {
        cin >> x >> y;
        ma2[x - 1].push_back(y - 1);
        ma2[y - 1].push_back(x - 1);
        if (s.count(make_pair(min(x - 1, y - 1), max(x - 1, y - 1)))) {
            vis[x - 1] = 1, vis[y - 1] = 1;
        }
    }
    priority_queue<trl, vector<trl>, greater<>> q;
    vvl dis(n + 1, vl(n + 1, LLONG_MAX / 3));
    dis[s1][s2] = 0;
    q.emplace(0, s1, s2);
    ll ans = LLONG_MAX / 3;
    while (!q.empty()) {
        auto [d, x, y] = q.top();
        q.pop();
        if (d > dis[x][y]) continue;
        if (x == y && vis[x]) ans = min(ans, d);
        for (auto& p : ma1[x]) {
            for (auto& q1 : ma2[y]) {
                ll tem = d + abs(p - q1);
                if (tem < dis[p][q1]) {
                    dis[p][q1] = tem;
                    q.emplace(tem, p, q1);
                }
            }
        }
    }
    cout << (ans == LLONG_MAX / 3 ? -1 : ans) << endl;
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
