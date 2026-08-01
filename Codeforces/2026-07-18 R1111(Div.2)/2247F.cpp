#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
const ll MOD = 998244353;
const ll LOG = 20;
class UnionFind {
    vector<int> fa;
    vector<int> siz;  // 集合大小
public:
    int cc;  // 连通块个数
    UnionFind(int n) : fa(n), siz(n, 1), cc(n) { ranges::iota(fa, 0); }
    int get(int x) {
        if (fa[x] != x) fa[x] = get(fa[x]);
        return fa[x];
    }
    bool is_same(int x, int y) { return get(x) == get(y); }
    bool merge(int from, int to) {
        int x = get(from), y = get(to);
        if (x == y) return false;
        fa[x] = y;
        siz[y] += siz[x];
        cc--;
        return true;
    }
    int get_size(int x) {  // 查询x所在集合大小
        return siz[get(x)];
    }
};
ll mul(ll x, ll y) { return x * y % MOD; }
ll qpow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> ma(n);
    rep(i, 0, n - 1) cin >> ma[i];
    ll tot = n * m;
    vl dep1(tot), dep2(tot);
    vl pre(tot), suf(tot);
    vector<bool> vis1(tot, false), vis2(tot, false);
    vvl up1(tot, vl(LOG, -1)), up2(tot, vl(LOG, -1));
    auto lca1 = [&](ll x, ll y) -> ll {
        if (dep1[x] < dep1[y]) swap(x, y);
        ll tem = dep1[x] - dep1[y];
        frep(i, LOG - 1, 0) {
            if (tem >> i & 1) x = up1[x][i];
        }
        if (x == y) return x;
        frep(i, LOG - 1, 0) {
            if (up1[x][i] != -1 && up1[x][i] != up1[y][i]) {
                x = up1[x][i], y = up1[y][i];
            }
        }
        return up1[x][0];
    };
    auto lca2 = [&](ll x, ll y) -> ll {
        if (dep2[x] < dep2[y]) swap(x, y);
        ll tem = dep2[x] - dep2[y];
        frep(i, LOG - 1, 0) {
            if (tem >> i & 1) x = up2[x][i];
        }
        if (x == y) return x;
        frep(i, LOG - 1, 0) {
            if (up2[x][i] != -1 && up2[x][i] != up2[y][i]) {
                x = up2[x][i], y = up2[y][i];
            }
        }
        return up2[x][0];
    };
    vis1[0] = 1, pre[0] = 0;
    rep(i, 0, LOG - 1) up1[0][i] = 0;
    rep(i, 1, tot - 1) {
        ll x = i / m, y = i % m;
        if (ma[x][y] == '0') continue;
        ll pre1 = (x != 0 && vis1[i - m] ? i - m : -1);
        ll pre2 = (y != 0 && vis1[i - 1] ? i - 1 : -1);
        if (pre1 == -1 && pre2 == -1) continue;
        vis1[i] = true;
        if (pre1 == -1)
            pre[i] = pre2;
        else if (pre2 == -1)
            pre[i] = pre1;
        else
            pre[i] = lca1(pre1, pre2);
        dep1[i] = dep1[pre[i]] + 1;
        up1[i][0] = pre[i];
        rep(j, 1, LOG - 1) {
            if (up1[i][j - 1] != -1) up1[i][j] = up1[up1[i][j - 1]][j - 1];
        }
    }
    vis2[tot - 1] = 1, suf[tot - 1] = tot - 1;
    rep(i, 0, LOG - 1) up2[tot - 1][i] = tot - 1;
    frep(i, tot - 2, 0) {
        ll x = i / m, y = i % m;
        if (ma[x][y] == '0') continue;
        ll suf1 = (x != n - 1 && vis2[i + m] ? i + m : -1);
        ll suf2 = (y != m - 1 && vis2[i + 1] ? i + 1 : -1);
        if (suf1 == -1 && suf2 == -1) continue;
        vis2[i] = true;
        if (suf1 == -1)
            suf[i] = suf2;
        else if (suf2 == -1)
            suf[i] = suf1;
        else
            suf[i] = lca2(suf1, suf2);
        dep2[i] = dep2[suf[i]] + 1;
        up2[i][0] = suf[i];
        rep(j, 1, LOG - 1) {
            if (up2[i][j - 1] != -1) up2[i][j] = up2[up2[i][j - 1]][j - 1];
        }
    }
    ll tot2 = 0;
    UnionFind u(tot);
    rep(i, 0, tot - 1) {
        if (!vis1[i] || !vis2[i]) {
            tot2++;
            continue;
        }
        ll tem = pre[i];
        if (suf[tem] == i) u.merge(i, pre[i]);
    }
    ll ans = 0;
    rep(i, 0, tot - 1) {
        if (!vis1[i] || !vis2[i]) continue;
        if (u.get(i) == i) {
            ans = (ans + (qpow(2, u.get_size(i)) - 1 + MOD) % MOD) % MOD;
        }
    }
    ans = (ans + (qpow(2, tot2) - 1 + MOD) % MOD) % MOD;
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