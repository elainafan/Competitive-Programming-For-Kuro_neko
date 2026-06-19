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
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i], a[i]--;
    rep(i, 0, n - 1) {
        cin >> b[i];
        if (b[i] != -1) b[i]--;
    }
    vl vis(n), fa(n), pos(n);
    vvl tem;
    int cnt = 0;
    rep(i, 0, n - 1) {
        if (vis[i]) continue;
        vl tem2;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            fa[cur] = cnt;
            pos[cur] = sz(tem2);
            tem2.push_back(cur);
            cur = a[cur];
        }
        tem.push_back(tem2);
        cnt++;
    }
    int m = sz(tem);
    vl id(m, -1), pos2(m, -1);
    rep(i, 0, n - 1) {
        if (b[i] == -1) continue;
        if (sz(tem[fa[i]]) != sz(tem[fa[b[i]]])) {
            cout << "NO" << endl;
            return;
        }
        int tem2 = (pos[b[i]] - pos[i] + sz(tem[fa[i]])) % sz(tem[fa[i]]);
        if (id[fa[i]] == -1) {
            id[fa[i]] = fa[b[i]];
            pos2[fa[i]] = tem2;
            continue;
        }
        if (id[fa[i]] != fa[b[i]] || tem2 != pos2[fa[i]]) {
            cout << "NO" << endl;
            return;
        }
    }
    vi vis2(m);
    rep(i, 0, m - 1) {
        if (id[i] == -1) continue;
        vis2[id[i]]++;
        if (vis2[id[i]] >= 2) {
            cout << "NO" << endl;
            return;
        }
    }
    vl mixx(m);
    vector<vector<pll>> tem2(n + 1);
    rep(i, 0, m - 1) {
        ll idx = -1, mixx2 = LLONG_MAX;
        rep(j, 0, sz(tem[i]) - 1) {
            if (tem[i][j] < mixx2) {
                idx = j;
                mixx2 = tem[i][j];
            }
        }
        mixx[i] = idx;
        if (!vis2[i]) tem2[sz(tem[i])].emplace_back(tem[i][idx], i);
    }
    vl cnt2(n + 1);
    rep(i, 1, n) { sort(all(tem2[i])); }
    rep(i, 0, n - 1) {
        if (id[fa[i]] != -1) continue;
        if (cnt2[sz(tem[fa[i]])] >= sz(tem2[sz(tem[fa[i]])])) {
            cout << "NO" << endl;
            return;
        }
        id[fa[i]] = tem2[sz(tem[fa[i]])][cnt2[sz(tem[fa[i]])]].second;
        pos2[fa[i]] = (mixx[tem2[sz(tem[fa[i]])][cnt2[sz(tem[fa[i]])]].second] - pos[i] + sz(tem[fa[i]])) % sz(tem[fa[i]]);
        cnt2[sz(tem[fa[i]])]++;
    }
    cout << "YES" << endl;
    vl res(n);
    rep(i, 0, m - 1) {
        rep(j, 0, sz(tem[i]) - 1) { res[tem[i][j]] = tem[id[i]][(j + pos2[i]) % sz(tem[i])]; }
    }
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
