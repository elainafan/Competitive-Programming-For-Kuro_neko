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
void solve1() {
    ll n, m, x, y;
    cin >> n >> m;
    vvl ma(n);
    rep(_, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vector<bool> vis(n, false);
    vl res(n);
    ll cnt = 0;
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        vis[x] = true;
        res[x] = ++cnt;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
        }
        cnt++;
        return;
    };
    rep(i, 0, n - 1) {
        if (!vis[i]) dfs(i, -1);
    }
    for (auto& p : res) cout << p << ' ';
    cout << endl;
    return;
}
void solve2() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<pll> ma;
    rep(i, 0, n - 1) ma.emplace_back(a[i], i + 1);
    sort(all(ma), [&](const pll& x, const pll& y) { return x.first < y.first; });
    vector<pll> edges;
    stack<ll> s;
    rep(i, 0, n - 1) {
        if (i > 0) {
            rep(j, 1, ma[i].first - ma[i - 1].first - 1) s.pop();
        }
        if (!s.empty()) edges.emplace_back(s.top(), ma[i].second);
        s.push(ma[i].second);
    }
    cout << sz(edges) << endl;
    for (auto& [x, y] : edges) cout << x << ' ' << y << endl;
    return;
}
void solve() {
    int t;
    string s;
    cin >> s >> t;
    while (t--) {
        if (s == "cat")
            solve1();
        else
            solve2();
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
