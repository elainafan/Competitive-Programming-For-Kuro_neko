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
class UnionFind {
    vector<int> fa;
    vector<int> siz;  // 集合大小

public:
    int cc;  // 连通块个数
    vi val;
    UnionFind(int n) : fa(n), siz(n, 1), cc(n), val(n, -1) { ranges::iota(fa, 0); }
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
    int get_val(int x) { return val[get(x)]; }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vi b(n);
    rep(i, 0, n - 1) cin >> b[i];
    UnionFind u(n);
    rep(i, 0, n - k - 1) {
        if (a[i] == a[i + k]) u.merge(i, i + k);
    }
    rep(i, 0, n - 1) {
        if (b[i] != -1) {
            if (u.get_val(i) != -1 && u.get_val(i) != b[i]) {
                cout << "NO" << endl;
                return;
            }
            u.val[u.get(i)] = b[i];
        }
    }
    rep(i, 0, n - k - 1) {
        if (a[i] != a[i + k]) {
            if (u.val[u.get(i)] != -1 && u.val[u.get(i)] != a[i]) {
                cout << "NO" << endl;
                return;
            }
            if (u.val[u.get(i + k)] != -1 && u.val[u.get(i + k)] != a[i + k]) {
                cout << "NO" << endl;
                return;
            }
            u.val[u.get(i)] = a[i];
            u.val[u.get(i + k)] = a[i + k];
        }
    }
    rep(i, 0, n - 1) {
        if (u.val[u.get(i)] != -1) b[i] = u.val[u.get(i)];
    }
    map<int, int> ma;
    rep(i, 0, k - 1) { ma[a[i]]++; }
    int tot = 0;
    rep(i, 0, k - 1) {
        if (b[i] != -1) {
            if (!ma.count(b[i])) {
                cout << "NO" << endl;
                return;
            }
            if (--ma[b[i]] == 0) ma.erase(ma.find(b[i]));
        } else
            tot++;
    }
    int tot2 = 0;
    for (auto& [x, y] : ma) tot2 += y;
    if (tot == tot2)
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
