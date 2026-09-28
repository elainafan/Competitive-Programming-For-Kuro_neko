// 模板地址：https://github.com/elainafan/Algorithms
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
void solve() {
    ll n, q, x;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl res;
    res.push_back(*max_element(all(a)) - *min_element(all(a)));
    ll cnt2 = 1;
    const int LOG = 30;  // long long 改成 60
    vector<array<int, 2>> son(1);
    vi cnt(1);
    auto insert = [&](ll x) -> void {
        int cur = 0;
        cnt[cur]++;
        frep(i, LOG, 0) {
            int b = x >> i & 1;
            if (!son[cur][b]) {
                son[cur][b] = sz(son);
                son.push_back({}), cnt.push_back(0);
            }
            cur = son[cur][b], cnt[cur]++;
        }
    };  // 插入整数 x
    auto erase = [&](ll x) -> void {
        int cur = 0;
        cnt[cur]--;
        frep(i, LOG, 0) {
            int b = x >> i & 1;
            cur = son[cur][b], cnt[cur]--;
        }
    };  // 删除一个已存在的整数 x
    auto count = [&](ll x) -> int {
        int cur = 0;
        frep(i, LOG, 0) {
            int b = x >> i & 1;
            if (!son[cur][b] || !cnt[son[cur][b]]) return 0;
            cur = son[cur][b];
        }
        return cnt[cur];
    };  // 查询整数 x 的出现次数
    auto query = [&](ll x, bool mx = true) -> ll {
        if (!cnt[0]) return -1;
        int cur = 0;
        ll ans = 0;
        frep(i, LOG, 0) {
            int b = x >> i & 1, to = b ^ mx;
            if (!son[cur][to] || !cnt[son[cur][to]]) to ^= 1;
            ans |= 1LL * (b ^ to) << i;
            cur = son[cur][to];
        }
        return ans;
    };  // mx=true 求最大异或，mx=false 求最小异或，空树返回 -1
    auto cntless = [&](ll x, ll k) -> ll {
        if (k <= 0) return 0;
        if (k >= (1LL << (LOG + 1))) return cnt[0];
        int cur = 0;
        ll ans = 0;
        frep(i, LOG, 0) {
            int xb = x >> i & 1, kb = k >> i & 1;
            if (kb) {
                if (son[cur][xb]) ans += cnt[son[cur][xb]];
                cur = son[cur][xb ^ 1];
            } else {
                cur = son[cur][xb];
            }
            if (!cur) break;
        }
        return ans;
    };  // 统计满足 (x^y)<k 的 y 的数量
    auto kth = [&](ll x, int k) -> ll {
        int cur = 0;
        ll ans = 0;
        frep(i, LOG, 0) {
            int b = x >> i & 1, to = son[cur][b];
            int siz = to ? cnt[to] : 0;
            if (k > siz) k -= siz, ans |= 1LL << i, to = son[cur][b ^ 1];
            cur = to;
        }
        return ans;
    };  // 查询第 k 小的 x^y，要求 1<=k<=cnt[0]
    while (true) {
        son.assign(1, {}), cnt.assign(1, 0);
        rep(i, 0, n - 1) insert(a[i]);
        priority_queue<trl, vector<trl>, greater<>> q;
        rep(i, 0, n - 1) { q.emplace(kth(a[i], 2), i, 1); }
        vl tem;
        rep(i, 1, 2 * n) {
            auto [val, x, ptr] = q.top();
            q.pop();
            if (i % 2 == 0) tem.push_back(val);
            if (ptr <= n - 2) q.emplace(kth(a[x], ptr + 2), x, ptr + 1);
        }
        if (tem[n - 1] == tem[0]) break;
        res.push_back(tem[n - 1] - tem[0]);
        a = tem;
        cnt2++;
    }
    rep(_, 0, q - 1) {
        cin >> x;
        cout << (x <= cnt2 - 1 ? res[x] : 0) << endl;
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
