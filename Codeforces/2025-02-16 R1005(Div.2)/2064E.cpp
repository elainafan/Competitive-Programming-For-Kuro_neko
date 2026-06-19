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
const ll MOD = 998244353;
class UnionFind {
public:
    int cc;  // 连通块个数
    vector<int> fa;
    vector<int> siz;  // 集合大小
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
void solve() {
    ll n;
    cin >> n;
    vl p(n), c(n);
    rep(i, 0, n - 1) cin >> p[i], p[i]--;
    rep(i, 0, n - 1) cin >> c[i];
    vl id(n);
    rep(i, 0, n - 1) id[p[i]] = i;
    UnionFind u(n);
    rep(i, 0, n - 2) {
        if (c[i] == c[i + 1]) u.merge(i, i + 1);
    }
    ll ans = 1;
    vl pre(n, -1), suf(n, -1);
    rep(i, 0, n - 1) { pre[i] = i - 1, suf[i] = i + 1; }
    suf[n - 1] = -1;
    rep(i, 0, n - 1) {
        ll tem = id[i];
        ans = ans * u.get_size(tem) % MOD;
        u.siz[u.get(tem)]--;
        ll pre2 = pre[tem], suf2 = suf[tem];
        if (pre2 != -1) suf[pre2] = suf2;
        if (suf2 != -1) pre[suf2] = pre2;
        if (pre2 != -1 && suf2 != -1 && c[pre2] == c[suf2]) u.merge(pre2, suf2);
    }
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
