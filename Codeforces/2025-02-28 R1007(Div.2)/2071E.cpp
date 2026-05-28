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
constexpr ll MOD = 998244353;
constexpr ll INV2 = 499122177;
ll mul(ll x, ll y) { return x * y % MOD; }
ll norm(ll x) { return (x % MOD + MOD) % MOD; }
ll qpow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD

// 注意：当MOD为质数时， (x/y)%MOD=(x*(y**(MOD-2)))%MOD，即y在模MOD意义下的逆元为b^{-1} \equiv b^{p-2} mod p

void solve() {
    ll n, x, y;
    cin >> n;
    vvi ma(n);
    vector<pll> co(n);
    vl live(n), dead(n);
    vl invd(n), sum(n);
    rep(i, 0, n - 1) cin >> co[i].first >> co[i].second;
    rep(i, 0, n - 1) {
        dead[i] = mul(co[i].first, qpow(co[i].second, MOD - 2));
        live[i] = norm(1 - dead[i]);
        invd[i] = mul(co[i].second, qpow(co[i].first, MOD - 2));
        sum[i] += mul(live[i], invd[i]);
    }
    vector<pll> edges;
    rep(i, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
        edges.emplace_back(x - 1, y - 1);
    }
    vl leaf(n), sumn(n), mult(n, 1);
    rep(i, 0, n - 1) {
        for (int& p : ma[i]) {
            mult[i] = mul(mult[i], dead[p]);
            sumn[i] = norm(sumn[i] + sum[p]);
        }
        leaf[i] = mul(mul(live[i], mult[i]), sumn[i]);
    }
    auto calc = [&](int x, int y) -> ll { return mul(mul(live[x], mult[x]), invd[y]); };
    auto calc2 = [&](int x, int y) -> ll { return mul(calc(x, y), norm(sumn[x] - sum[y])); };
    ll tot = 0, tot2 = 0;
    rep(i, 0, n - 1) {
        tot = norm(tot + leaf[i]);
        tot2 = norm(tot2 + mul(leaf[i], leaf[i]));
    }
    ll ans = mul(norm(mul(tot, tot) - tot2), INV2);
    for (auto& [x, y] : edges) {
        ans = norm(ans + mul(calc(x, y), calc(y, x)) - mul(leaf[x], leaf[y]));
    }
    rep(i, 0, n - 1) {
        ll totcalc = 0, totcalc_2 = 0;
        ll totcalc2 = 0, totcalc2_2 = 0;
        ll totleaf = 0, totleaf_2 = 0;
        for (int& p : ma[i]) {
            totcalc = norm(totcalc + calc(p, i));
            totcalc_2 = norm(totcalc_2 + mul(calc(p, i), calc(p, i)));
            totcalc2 = norm(totcalc2 + calc2(p, i));
            totcalc2_2 = norm(totcalc2_2 + mul(calc2(p, i), calc2(p, i)));
            totleaf = norm(totleaf + leaf[p]);
            totleaf_2 = norm(totleaf_2 + mul(leaf[p], leaf[p]));
        }
        ans = norm(ans + mul(live[i], mul(norm(norm(mul(totcalc, totcalc) - totcalc_2)), INV2)) +
                   mul(dead[i], mul(norm(norm(mul(totcalc2, totcalc2) - totcalc2_2)), INV2)) -
                   mul(norm(norm(mul(totleaf, totleaf) - totleaf_2)), INV2));
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
