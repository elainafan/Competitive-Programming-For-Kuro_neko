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
    ll n, x, y;
    cin >> n;
    vl a(n);
    vvl ma(n);
    vvl ma2(n);
    rep(i, 0, n - 1) cin >> a[i], a[i] = a[i] % 2;
    vl cnt(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        x--, y--;
        cnt[y] += a[x], cnt[x] += a[y];
        if (a[x] && a[y]) {
            ma[x].push_back(y);
            ma[y].push_back(x);
        }
        if (a[x] && !a[y]) ma2[x].push_back(y);
        if (!a[x] && a[y]) ma2[y].push_back(x);
    }
    rep(i, 0, n - 1) {
        if (!a[i] && !cnt[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    vl res;
    vl vis(n), siz(n);
    vl tem(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        int tem2 = 1;
        vis[x] = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            tem2 += siz[p];
        }
        siz[x] = tem2;
        return;
    };
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            if (!(siz[p] % 2)) dfs2(p, x);
        }
        res.push_back(x);
        for (auto& p : ma2[x]) {
            if (!tem[p]) {
                tem[p] = 1;
                res.push_back(p);
            }
        }
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            if (siz[p] % 2) dfs2(p, x);
        }
        return;
    };
    rep(i, 0, n - 1) {
        if (!a[i]) {
            if (cnt[i] % 2 == 1) {
                tem[i] = 1;
                res.push_back(i);
            }
        }
    }
    rep(i, 0, n - 1) {
        if (a[i] && !vis[i]) {
            dfs(i, -1);
            if (!(siz[i] % 2)) {
                cout << "NO" << endl;
                return;
            }
            dfs2(i, -1);
        }
    }
    cout << "YES" << endl;
    rep(i, 0, n - 1) cout << res[i] + 1 << ' ';
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
