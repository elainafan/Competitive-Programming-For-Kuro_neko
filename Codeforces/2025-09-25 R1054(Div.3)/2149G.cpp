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

struct ChairmanTree {
    struct Node {
        int ls = 0, rs = 0, cnt = 0;
    };

    vector<Node> tr;
    vector<int> root;
    vector<ll> vals;

    ChairmanTree(const vector<ll>& a) {
        vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int n = a.size();

        tr.reserve((n + 1) * 20);
        tr.push_back(Node());

        root.assign(n + 1, 0);
        root[0] = 0;

        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(vals.begin(), vals.end(), a[i - 1]) - vals.begin() + 1;
            root[i] = add(root[i - 1], 1, vals.size(), pos);
        }
    }

    int add(int old, int l, int r, int p) {
        int o = copy_node(old);
        tr[o].cnt++;

        if (l == r) return o;

        int m = (l + r) >> 1;

        if (p <= m)
            tr[o].ls = add(tr[old].ls, l, m, p);
        else
            tr[o].rs = add(tr[old].rs, m + 1, r, p);

        return o;
    }

    ll kth(int l, int r, int k) const {
        return vals[kth(root[l - 1], root[r], 1, vals.size(), k) - 1];
    }

    ll leq(int l, int r, ll x) const {
        int pos = upper_bound(vals.begin(), vals.end(), x) - vals.begin();

        if (!pos) return 0;

        return query(root[l - 1], root[r], 1, vals.size(), pos);
    }

private:
    int copy_node(int old) {
        tr.push_back(tr[old]);
        return tr.size() - 1;
    }

    int kth(int old, int now, int l, int r, int k) const {
        if (l == r) return l;

        int left_cnt = tr[tr[now].ls].cnt - tr[tr[old].ls].cnt;
        int m = (l + r) >> 1;

        if (k <= left_cnt)
            return kth(tr[old].ls, tr[now].ls, l, m, k);

        return kth(tr[old].rs, tr[now].rs, m + 1, r, k - left_cnt);
    }

    ll query(int old, int now, int l, int r, int qr) const {
        if (r <= qr) return tr[now].cnt - tr[old].cnt;

        int m = (l + r) >> 1;

        ll res = query(tr[old].ls, tr[now].ls, l, m, qr);

        if (qr > m) {
            res += query(tr[old].rs, tr[now].rs, m + 1, r, qr);
        }

        return res;
    }
};

// 使用：ChairmanTree ct(a);
// ct.kth(l, r, k)：查询 1-indexed 区间 [l, r] 第 k 小的原值
// ct.leq(l, r, x)：查询区间 [l, r] 内 <= x 的数量和总和
//
// vector<ll> a(n);               // a 是 0-indexed 原数组
// ChairmanTree ct(a);
// ll kth_val = ct.kth(l, r, k);  // l, r, k 都按 1-indexed 传
// auto [cnt, sum] = ct.leq(l, r, limit);
void solve() {
    ll n, q, x, y;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ChairmanTree ct(a);
    rep(i, 0, q - 1) {
        cin >> x >> y;
        ll l = y - x + 1;
        ll tem = l / 3 + 1;
        ll tem2 = l * 2 / 3 + 1;
        vl res;
        res.push_back(ct.kth(x, y, tem));
        res.push_back(ct.kth(x, y, tem2));
        if (res[0] == res[1]) {
            ll cnt = ct.leq(x, y, res[0]) - ct.leq(x, y, res[0] - 1);
            if (cnt > l / 3)
                cout << res[0] << endl;
            else
                cout << -1 << endl;
            continue;
        }
        vl res2;
        ll cnt = ct.leq(x, y, res[0]) - ct.leq(x, y, res[0] - 1);
        ll cnt2 = ct.leq(x, y, res[1]) - ct.leq(x, y, res[1] - 1);
        if (cnt > l / 3) res2.push_back(res[0]);
        if (cnt2 > l / 3) res2.push_back(res[1]);
        if (res2.empty())
            cout << -1 << endl;
        else {
            ranges::sort(res2);
            for (auto& p : res2) cout << p << ' ';
            cout << endl;
        }
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
