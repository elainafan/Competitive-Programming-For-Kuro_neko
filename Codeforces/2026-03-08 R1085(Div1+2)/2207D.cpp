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
    int n, k, v, x, y;
    cin >> n >> k >> v;
    v--;
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vi dis(n, 1);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        bool isleaf = true;
        dis[x] = INT_MAX / 3;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            isleaf = false;
            dfs(p, x);
            if (dis[x] + dis[p] < k + 3) dis[x] = 1;
            dis[x] = min(dis[x], dis[p] + 1);
        }
        if (isleaf) dis[x] = 1;
    };
    dfs(v, -1);
    if (dis[v] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
