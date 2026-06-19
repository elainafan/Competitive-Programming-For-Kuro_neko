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
const ll MX = 20;
void solve() {
    ll n, q, x, y, z;
    cin >> n >> z;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pa(n + 1, n);
    vvl up(n + 1, vl(MX, n));
    ll r = 0;
    rep(l, 0, n - 1) {
        while (r <= n - 1 && a[r] <= a[l] + z) r++;
        pa[l] = r;
    }
    pa[n] = n;
    rep(i, 0, n) up[i][0] = pa[i];
    rep(j, 1, MX - 1) {
        rep(i, 0, n) {
            ll mid = up[i][j - 1];
            up[i][j] = up[mid][j - 1];
        }
    }
    vl dep(n + 1);
    dep[n] = 0;
    frep(i, n - 1, 0) dep[i] = dep[pa[i]] + 1;
    auto lca = [&](ll u, ll v) {
        if (dep[u] > dep[v]) swap(u, v);
        ll d = dep[v] - dep[u];
        rep(j, 0, MX - 1) {
            if ((d >> j) & 1) v = up[v][j];
        }
        if (u == v) return u;
        frep(j, MX - 1, 0) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    };
    vector<vector<pll>> up2(n + 1, vector<pll>(MX, {n, 0}));
    rep(i, 0, n - 1) {
        ll tem = lca(i, i + 1);
        up2[i][0].first = tem;
        up2[i][0].second = dep[i] + dep[i + 1] - 2 * dep[tem];
    }
    rep(j, 1, MX - 1) {
        rep(i, 0, n) {
            ll mid = up2[i][j - 1].first;
            up2[i][j].first = up2[mid][j - 1].first;
            up2[i][j].second = up2[i][j - 1].second + up2[mid][j - 1].second;
        }
    }
    auto calc = [&](ll x, ll y) {
        ll tem = 1;
        frep(i, MX - 1, 0) {
            if (up[x][i] <= y) {
                x = up[x][i];
                tem += (1LL << i);
            }
        }
        return tem;
    };
    cin >> q;
    rep(i, 0, q - 1) {
        cin >> x >> y;
        x--, y--;
        if (y - x + 1 <= 2) {
            cout << y - x + 1 << endl;
            continue;
        }
        ll tem = 0;
        frep(i, MX - 1, 0) {
            if (up2[x][i].first <= y) {
                tem += up2[x][i].second;
                x = up2[x][i].first;
            }
        }
        if (x <= y) tem += calc(x, y);
        if (x + 1 <= y) tem += calc(x + 1, y);
        cout << tem << endl;
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
