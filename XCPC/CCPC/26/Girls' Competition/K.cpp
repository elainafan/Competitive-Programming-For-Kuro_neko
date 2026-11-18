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
    ll n, ka, km, x, y, a, r, op;
    cin >> n >> ka >> km;
    vector<array<ll, 4>> ma;
    vector<array<ll, 4>> mp;
    rep(_, 0, n - 1) {
        cin >> op >> x >> y >> r >> a;
        if (op == 1)
            ma.push_back({x, y, a, r});
        else
            mp.push_back({x, y, a, r});
    }
    ll m1 = sz(ma), m2 = sz(mp);
    ka = min(ka, m1), km = min(km, m2);
    ll ans = -INF;
    vector<bool> vis(m1, false);
    vl used;
    auto dfs = [&](this auto&& dfs, int pos) -> void {
        if (pos == ka) {
            auto v = mp;
            for (auto& p : ma) v.push_back(p);
            for (auto& p : used) {
                ll id = p + m2;
                ll r = v[id][3];
                rep(i, 0, n - 1) {
                    if ((v[i][0] - v[id][0]) * (v[i][0] - v[id][0]) + (v[i][1] - v[id][1]) * (v[i][1] - v[id][1]) <= r * r) v[i][3] *= 2;
                }
            }
            vl mask(n);
            rep(i, 0, m2 - 1) {
                rep(j, 0, n - 1) {
                    if ((v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) + (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]) <= v[i][3] * v[i][3]) mask[j] |= (1 << i);
                }
            }
            rep(i, 0, (1 << m2) - 1) {
                if (popcount((unsigned)i) != km) continue;
                ll tot = 0;
                rep(j, 0, n - 1) {
                    ll cnt = popcount((unsigned)(mask[j] & i));
                    tot += v[j][2] * v[j][3] * v[j][3] * (1LL << cnt);
                }
                ans = max(ans, tot);
            }
            return;
        }
        rep(i, 0, m1 - 1) {
            if (vis[i]) continue;
            vis[i] = true;
            used.push_back(i);
            dfs(pos + 1);
            used.pop_back();
            vis[i] = false;
        }
        return;
    };
    dfs(0);
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
