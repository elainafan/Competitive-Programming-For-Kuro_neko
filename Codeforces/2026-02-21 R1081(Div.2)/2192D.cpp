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
    vl a(n);
    vvi ma(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl res(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vi dep(n);
    vi maxx(n);
    vl tem(n);
    vl tem2(n);
    vl tem3(n);
    vl cnt(n);
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
        dep[x] = d;
        maxx[x] = dep[x];
        tem2[x] = a[x];
        int idx = -1;
        ll d1 = d, d2 = d;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x, d + 1);
            tem2[x] += tem2[p];
            tem3[x] += tem3[p] + tem2[p];
            if (maxx[p] > d1) {
                d2 = d1;
                d1 = maxx[p];
                idx = p;
            } else if (maxx[p] > d2)
                d2 = maxx[p];
        }
        if (idx != -1) {
            cnt[x] = max(cnt[x], cnt[idx]);
            cnt[x] = max(cnt[x], tem2[idx] * (d2 - dep[idx] + 1));
        }
        for (int& p : ma[x]) {
            if (p == pa || p == idx) continue;
            cnt[x] = max(cnt[x], tem2[p] * (d1 - dep[p] + 1));
        }
        res[x] = tem3[x] + cnt[x];
        maxx[x] = d1;
        return;
    };
    dfs(0, -1, 0);
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
