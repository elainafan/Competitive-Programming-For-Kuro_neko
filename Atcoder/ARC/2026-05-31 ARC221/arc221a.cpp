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
constexpr ll INV2 = 499122177;
constexpr ll MOD = 998244353;
ll mul(ll x, ll y) { return x * y % MOD; }
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

ll Phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res = res / n * (n - 1);
    return res;
}

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

ll norm(ll x, ll mod) {
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
    return {norm(x, step), step};
}

// 求 a 在 mod 下的逆元，要求 gcd(a, mod) = 1。
ll inv_mod(ll a, ll mod) {
    ll x, y;
    exgcd(a, mod, x, y);
    return norm(x, mod);
}

// 扩展 CRT：模数不一定互质。
pair<ll, ll> excrt(const vector<ll>& r, const vector<ll>& m) {
    ll ans = norm(r[0], m[0]);
    ll mod = m[0];
    for (int i = 1; i < (int)r.size(); i++) {
        ll b = norm(r[i] - ans, m[i]);
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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll tem = abs(c * b - a * d);
    if (tem == 0) {
        ll tem2 = __gcd(a, c);
        ll a1 = a / tem2, c1 = c / tem2;
        ll tem3 = b / a1;
        ll ans1 = mul(tem2, mul(INV2, mul(n, n + 1)));
        ll ans2 = mul(tem3, n);
        cout << (ans1 + ans2) % MOD << endl;
    } else {
        ll ans = 0;
        auto calc = [&](ll tem2) -> void {
            auto [x1, y1] = linear_congruence(a, -b, tem2);
            if (x1 == -1) return;
            auto [x2, y2] = linear_congruence(c, -d, tem2);
            if (x2 == -1) return;
            auto [x, y] = excrt(vl{x1, x2}, vl{y1, y2});
            if (x == -1) return;
            ll cnt = 0;
            x = norm(x, y);
            if (x == 0)
                cnt = n / y;
            else if (x <= n)
                cnt = (n - x) / y + 1;
            ans = (ans + mul(Phi(tem2) % MOD, cnt)) % MOD;
        };
        for (ll i = 1; i * i <= tem; i++) {
            if (tem % i == 0) {
                calc(i);
                if (i * i != tem) calc(tem / i);
            }
        }
        cout << ans << endl;
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
