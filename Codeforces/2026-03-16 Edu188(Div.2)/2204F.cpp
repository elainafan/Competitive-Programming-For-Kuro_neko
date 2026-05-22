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
constexpr int MOD = 998244353;
ll qpow(ll x, int n) {
    ll res = 1;
    for (; n; n >>= 1) {
        if (n % 2) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}
void solve() {
    ll n, m, k;
    cin >> n >> m;
    vector<pii> a(n);
    rep(i, 0, n - 1) {
        cin >> a[i].second;
        a[i].first = 1;
    }
    vector<pll> b(n);
    ll tot = 0;
    vi r(n, n);
    vi l(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()].second > a[i].second) s.pop();
        if (!s.empty()) r[i] = s.top();
        s.push(i);
    }  // 求右边第一个小于的下标
    while (!s.empty()) s.pop();
    for (int i = 0; i <= n - 1; i++) {
        while (!s.empty() && a[s.top()].second >= a[i].second) s.pop();
        if (!s.empty()) l[i] = s.top();
        s.push(i);
    }  // 求左边第一个小于的下标
    rep(i, 0, n - 1) {
        b[i].first = a[i].second;
        b[i].second = 1LL * (r[i] - i) * (i - l[i]);
    }
    rep(i, 0, n - 1) {
        tot += 1LL * (i + 1) * (n - i) % MOD * qpow(a[i].second, MOD - 2) % MOD;
        tot %= MOD;
    }
    ranges::sort(b);
    vl pre1(n);
    vl suf1(n);
    vl pre2(n);
    pre1[0] = b[0].second % MOD;
    rep(i, 1, n - 1) { pre1[i] = (pre1[i - 1] + b[i].second % MOD) % MOD; }
    pre2[0] = b[0].second % MOD * (((2 - b[0].first % MOD - qpow(b[0].first, MOD - 2)) % MOD + MOD) % MOD) % MOD;
    rep(i, 1, n - 1) {
        ll tem = b[i].second % MOD * (((2 - b[i].first % MOD - qpow(b[i].first, MOD - 2)) % MOD + MOD) % MOD) % MOD;
        pre2[i] = (pre2[i - 1] + tem) % MOD;
    }
    suf1[n - 1] = b[n - 1].second % MOD * qpow(b[n - 1].first, MOD - 2) % MOD;
    frep(i, n - 2, 0) {
        ll tem = b[i].second % MOD * qpow(b[i].first, MOD - 2) % MOD;
        suf1[i] = (suf1[i + 1] + tem) % MOD;
    }
    rep(i, 0, m - 1) {
        cin >> k;
        auto x = ranges::upper_bound(b, make_pair(k, LLONG_MAX));
        int tem = x - b.begin();
        ll tem2, tem3;
        if (tem == 0)
            tem2 = 0;
        else
            tem2 = (k * pre1[tem - 1] % MOD + pre2[tem - 1]) % MOD;
        if (tem == n)
            tem3 = 0;
        else
            tem3 = k * suf1[tem] % MOD;
        cout << (tot + tem2 + tem3) % MOD << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
