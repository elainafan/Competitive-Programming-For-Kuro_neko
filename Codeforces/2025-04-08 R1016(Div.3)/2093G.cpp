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
// 01-Trie 短版：只留最常用的插入和最大异或
// 需要删除就给每个点 cnt--；需要 min_xor 就优先走同位。
template <int LOG = 30>
struct BinaryTrieLite {
    struct Node {
        int ch[2];
        int cnt;
        int idx;

        Node(int x = -1) : cnt(0), idx(x) { ch[0] = ch[1] = -1; }
    };

    vector<Node> tr;

    BinaryTrieLite() { tr.push_back(Node()); }

    int newnode() {
        tr.push_back(Node());
        return (int)tr.size() - 1;
    }

    void insert(long long x, int idx) {
        int u = 0;
        tr[u].cnt++;
        tr[u].idx = max(tr[u].idx, idx);
        for (int i = LOG; i >= 0; i--) {
            if (u == -1) break;
            int b = (x >> i) & 1;
            if (tr[u].ch[b] == -1) {
                tr[u].ch[b] = newnode();
            }
            u = tr[u].ch[b];
            tr[u].cnt++;
            tr[u].idx = max(tr[u].idx, idx);
        }
    }

    int query(ll x, ll k) {
        int u = 0;
        int ans = -1;
        frep(i, LOG, 0) {
            if (u == -1) break;
            int tem = (x >> i) & 1;
            int tem2 = (k >> i) & 1;
            if (tem2 == 0) {
                int v = tr[u].ch[tem ^ 1];
                if (v != -1) ans = max(ans, tr[v].idx);
                u = tr[u].ch[tem];
            } else {
                u = tr[u].ch[tem ^ 1];
            }
        }
        if (u != -1) ans = max(ans, tr[u].idx);
        return ans;
    }

    long long max_xor(long long x) {
        if (tr[0].cnt == 0) return 0;
        int u = 0;
        long long ans = 0;
        for (int i = LOG; i >= 0; i--) {
            int b = (x >> i) & 1;
            int v = tr[u].ch[b ^ 1];
            if (v != -1 && tr[v].cnt > 0) {
                ans |= 1LL << i;
                u = v;
            } else {
                u = tr[u].ch[b];
            }
        }
        return ans;
    }
};
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    BinaryTrieLite<30> trie;
    int ans = INT_MAX;
    rep(r, 0, n - 1) {
        int tem = trie.query(a[r], k);
        if (tem != -1) ans = min(ans, r - tem + 1);
        trie.insert(a[r], r);
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
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
