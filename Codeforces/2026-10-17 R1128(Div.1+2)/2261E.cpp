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
void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack<ll> st;
    st.push(0);
    vvl ma(n);
    ll tot = 0;
    rep(i, 0, n - 1) {
        if (s[i] == '(') {
            ma[st.top()].push_back(++tot);
            ma[tot].push_back(st.top());
            st.push(tot);
        } else {
            st.pop();
        }
    }
    vl siz(n), dep(n), pa(n);
    auto dfs = [&](this auto&& dfs, int x, int fa, int d) -> void {
        pa[x] = fa;
        dep[x] = d;
        siz[x] = 1;
        for (auto& p : ma[x]) {
            if (p == fa) continue;
            dfs(p, x, d + 1);
            siz[x] += siz[p];
        }
        return;
    };
    dfs(0, -1, 0);
    ll ans = 0;
    vl tem, val(n);
    auto dfs2 = [&](this auto&& dfs2, int x, int fa) -> void {
        if (x != 0) {
            tem.push_back(val[x]);
            auto pos = ranges::lower_bound(tem, val[x] - k) - tem.begin();
            ans = max(ans, 1LL * sz(tem) - pos);
            if (val[x] <= k) ans = max(ans, min(n / 2, k + dep[x]));
        }
        ll cnt = 0;
        for (auto& p : ma[x]) {
            if (p == fa) continue;
            val[p] = val[x] + cnt;
            dfs2(p, x);
            cnt += siz[p];
        }
        if (x != 0) tem.pop_back();
        return;
    };
    dfs2(0, -1);
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
