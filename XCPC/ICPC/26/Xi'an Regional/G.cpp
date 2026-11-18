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
    ll n;
    cin >> n;
    vl a(1 << n);
    rep(i, 0, (1 << n) - 1) cin >> a[i];
    auto dfs = [&](this auto&& dfs, int l, int r) -> array<ll, 3> {
        if (l == r) return {a[l], a[l], 0};
        ll mid = (l + r) / 2;
        auto left = dfs(l, mid), right = dfs(mid + 1, r);
        ll mn = min(left[0], right[0]);
        return {mn, max({left[1], right[1], left[2] + right[2]}), max({left[1] - mn, right[1] - mn, left[2] + right[2]})};
    };
    cout << dfs(0, (1 << n) - 1)[1] << endl;
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
