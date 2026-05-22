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
void solve() {
    int n, x, y;
    cin >> n;
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    map<int, int> s;
    map<int, map<int, vi>> s2;
    int maxx = INT_MIN;
    vector<pii> tem(n);
    vi depth(n);
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
        s[d]++;
        depth[x] = d;
        int cnt = 0;
        tem[x].first = pa;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            cnt++;
            dfs(p, x, d + 1);
        }
        if (s.count(d + 1) && cnt == s[d + 1])
            maxx = max(maxx, cnt + 1);
        else
            maxx = max(maxx, cnt);
        return;
    };
    dfs(0, -1, 0);
    for (auto& [x, y] : s) {
        maxx = max(maxx, y);
    }
    cout << maxx << endl;
    int md = sz(s);
    vvi ma2(md);
    rep(i, 0, n - 1) ma2[depth[i]].push_back(i);
    tem[0].second = 0;
    rep(i, 1, md - 1) {
        sort(all(ma2[i]), [&](const int& x, const int& y) { return tem[tem[x].first].second < tem[tem[y].first].second; });
        vector<bool> vis(maxx, false);
        rep(j, 0, sz(ma2[i]) - 1) { vis[(tem[tem[ma2[i][j]].first].second - j + maxx) % maxx] = true; }
        int idx = 0;
        while (vis[idx]) idx++;
        rep(j, 0, sz(ma2[i]) - 1) { tem[ma2[i][j]].second = (j + idx + maxx) % maxx; }
    }
    vvi res(maxx);
    rep(i, 0, n - 1) { res[tem[i].second].push_back(i); }
    for (auto& p : res) {
        cout << sz(p) << endl;
        for (auto& q : p) cout << q + 1 << ' ';
        cout << endl;
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
