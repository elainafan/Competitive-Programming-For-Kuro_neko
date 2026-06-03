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
#define vb vector<bool>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
/*
CRT / exCRT

求解同余方程组：
    x = r[i] (mod m[i])

用法：
    vector<ll> r = {2, 3, 2};
    vector<ll> m = {3, 5, 7};

    auto [x, mod] = crt(r, m);    // 要求 m 两两互质
    auto [x, mod] = excrt(r, m);  // m 不要求互质

    auto [ok, x0, y0, g] = linear_diophantine(a, b, c);  // ax + by = c
    auto [x0, step] = linear_congruence(a, b, m);        // ax = b (mod m)

返回值：
    若有解，返回 {x, mod}，表示所有解为 x + k * mod，且 0 <= x < mod。
    若无解，返回 {-1, -1}。

    linear_diophantine：
        若 ok = true，返回一组解 (x0, y0)，g = gcd(a, b)。
        所有整数解：
            x = x0 + k * (b / g)
            y = y0 - k * (a / g)

    linear_congruence：
        若有解，返回 {x0, step}，表示所有解为 x = x0 + k * step。
        其中 0 <= x0 < step，step = m / gcd(a, m)。
        若无解，返回 {-1, -1}。

注意：
    1. m[i] 必须为正数。
    2. 若最终 lcm 超过 long long，需要自己改成 __int128 或高精度。
    3. crt 实际上调用 excrt，只是语义上提醒模数互质时可用。
*/

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

ll norm_mod(ll x, ll mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

struct Diophantine {
    bool ok;
    ll x, y, g;
};

// 解 ax + by = c。
Diophantine linear_diophantine(ll a, ll b, ll c) {
    if (a == 0 && b == 0) return {c == 0, 0, 0, 0};

    ll x, y;
    ll g = exgcd(abs(a), abs(b), x, y);
    if (c % g != 0) return {false, 0, 0, g};

    x = (ll)((__int128)x * (c / g));
    y = (ll)((__int128)y * (c / g));
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return {true, x, y, g};
}

// 解 ax = b (mod mod)。
pair<ll, ll> linear_congruence(ll a, ll b, ll mod) {
    ll x, y;
    ll g = exgcd(abs(a), mod, x, y);
    if (b % g != 0) return {-1, -1};

    ll step = mod / g;
    x = (ll)((__int128)x * (b / g) % step);
    if (a < 0) x = -x;
    return {norm_mod(x, step), step};
}

// 求 a 在 mod 下的逆元，要求 gcd(a, mod) = 1。
ll inv_mod(ll a, ll mod) {
    ll x, y;
    exgcd(a, mod, x, y);
    return norm_mod(x, mod);
}

// 扩展 CRT：模数不一定互质。
pair<ll, ll> excrt(const vector<ll>& r, const vector<ll>& m) {
    ll ans = norm_mod(r[0], m[0]);
    ll mod = m[0];
    for (int i = 1; i < (int)r.size(); i++) {
        ll b = norm_mod(r[i] - ans, m[i]);
        ll g = gcd(mod, m[i]);
        if (b % g != 0) return {-1, -1};

        ll p = mod / g;
        ll q = m[i] / g;
        ll t = (ll)((__int128)(b / g) * inv_mod(p % q, q) % q);

        ll lcm = (ll)((__int128)mod / g * m[i]);
        ans = (ans + (ll)((__int128)mod * t % lcm)) % lcm;
        mod = lcm;
    }
    return {ans, mod};
}

// 普通 CRT：模数两两互质。
pair<ll, ll> crt(const vector<ll>& r, const vector<ll>& m) { return excrt(r, m); }

void solve() {
    ll n, q;
    cin >> n >> q;
    vl pa(n);
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> pa[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
    }
    vl ti(n);
    rep(i, 1, n - 1) cin >> ti[i];
    vl queries(q);
    vl ans(q);
    vvl tem(n);
    vb pd(n, false);
    rep(i, 0, q - 1) cin >> queries[i];
    rep(i, 0, q - 1) tem[0].push_back(i);
    vl dis(n);
    rep(i, 1, n - 1) dis[i] = dis[pa[i]] + ti[i];
    vl mod(n, 1), re(n);
    rep(i, 0, n - 1) {
        if (tem[i].empty()) continue;
        if (ma[i].empty()) {
            for (auto& p : tem[i]) ans[p] = i;
            continue;
        }
        if (pd[i]) {
            ll tem2 = queries[tem[i][0]];
            ll tem3 = (tem2 + dis[i]) % sz(ma[i]);
            pd[ma[i][tem3]] = true;
            re[ma[i][tem3]] = tem2;
            mod[ma[i][tem3]] = 1e18 + 1;
            tem[ma[i][tem3]] = move(tem[i]);
            continue;
        }
        if (mod[i] % sz(ma[i]) == 0) {
            ll tem2 = (re[i] + dis[i]) % sz(ma[i]);
            mod[ma[i][tem2]] = mod[i];
            re[ma[i][tem2]] = re[i];
            tem[ma[i][tem2]] = move(tem[i]);
            continue;
        }
        vvl tem2(sz(ma[i]));
        for (auto& p : tem[i]) {
            tem2[(queries[p] + dis[i]) % sz(ma[i])].push_back(p);
        }
        i128 tem3 = (i128)mod[i] / __gcd(mod[i], 1LL * sz(ma[i])) * sz(ma[i]);
        rep(j, 0, sz(ma[i]) - 1) {
            if (tem2[j].empty()) continue;
            if (tem3 > 1e18) {
                pd[ma[i][j]] = true;
                re[ma[i][j]] = queries[tem2[j][0]];
                mod[ma[i][j]] = 1e18 + 1;
                tem[ma[i][j]] = move(tem2[j]);
                continue;
            }
            ll re2 = norm_mod(j - dis[i], sz(ma[i]));
            auto [x, y] = excrt({re[i], re2}, {mod[i], sz(ma[i])});
            re[ma[i][j]] = x;
            mod[ma[i][j]] = y;
            tem[ma[i][j]] = move(tem2[j]);
        }
    }
    rep(i, 0, q - 1) cout << ans[i] + 1 << ' ';
    cout << endl;
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
