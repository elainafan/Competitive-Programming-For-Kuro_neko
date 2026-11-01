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
template <typename T = long long>
class Tree2D {
    int n, m;
    vector<vector<T>> tree;

    void build() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int nxt = j + (j & -j);
                if (nxt <= m) tree[i][nxt] += tree[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            int nxt = i + (i & -i);
            if (nxt <= n) {
                for (int j = 1; j <= m; j++) {
                    tree[nxt][j] += tree[i][j];
                }
            }
        }
    }

public:
    Tree2D(int n, int m, T val = 0) : n(n), m(m), tree(n + 1, vector<T>(m + 1, val)) { build(); }

    Tree2D(const vector<vector<T>>& data) : n(data.size()), m(n ? data[0].size() : 0), tree(n + 1, vector<T>(m + 1)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                tree[i][j] = data[i - 1][j - 1];
            }
        }
        build();
    }

    // 单点加：a[x][y] += val
    void add(int x, int y, T val = 1) {
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= m; j += j & -j) {
                tree[i][j] += val;
            }
        }
    }

    // 前缀和：[0,x] × [0,y]；x 或 y 为 -1 时返回 0
    T pre(int x, int y) const {
        T res = 0;
        for (int i = x + 1; i > 0; i &= i - 1) {
            for (int j = y + 1; j > 0; j &= j - 1) {
                res += tree[i][j];
            }
        }
        return res;
    }

    // 矩形和：左上角 (x1,y1)，右下角 (x2,y2)
    T query(int x1, int y1, int x2, int y2) const {
        if (x2 < x1 || y2 < y1) return 0;
        return pre(x2, y2) - pre(x1 - 1, y2) - pre(x2, y1 - 1) + pre(x1 - 1, y1 - 1);
    }
};
void solve() {
    ll n, q, x1, y1, x2, y2, x;
    char op;
    cin >> n >> q;
    vvl a(n, vl(n)), b(n, vl(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) cin >> a[i][j]; }
    rep(i, 0, n - 1) { rep(j, 0, n - 1) cin >> b[i][j]; }
    vvl d(n, vl(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) d[i][j] = a[i][j] - b[i][j]; }
    frep(i, n - 1, 0) {
        frep(j, n - 1, 0) {
            if (i > 0) d[i][j] -= d[i - 1][j];
            if (j > 0) d[i][j] -= d[i][j - 1];
            if (i > 0 && j > 0) d[i][j] += d[i - 1][j - 1];
        }
    }
    vvl cnt(n, vl(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) cnt[i][j] = (d[i][j] != 0); }
    Tree2D<ll> tree(cnt);
    auto work = [&](ll x, ll y, ll z) {
        if (x < 0 || y < 0 || x >= n || y >= n) return;
        tree.add(x, y, -(d[x][y] != 0));
        d[x][y] += z;
        tree.add(x, y, (d[x][y] != 0));
    };
    rep(_, 0, q - 1) {
        cin >> op;
        if (op == 'U') {
            cin >> x1 >> y1 >> x2 >> y2 >> x;
            x1--, y1--, x2--, y2--;
            work(x1, y1, x), work(x2 + 1, y2 + 1, x), work(x1, y2 + 1, -x), work(x2 + 1, y1, -x);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            cout << (tree.query(x1 + 1, y1 + 1, x2, y2) == 0 ? "Yes" : "No") << endl;
        }
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
