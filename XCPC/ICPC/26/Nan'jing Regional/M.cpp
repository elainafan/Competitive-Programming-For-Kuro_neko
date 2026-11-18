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
struct PointI {
    i128 x = 0, y = 0;
    auto operator+(const PointI& p) const -> PointI { return {x + p.x, y + p.y}; }
    auto operator-(const PointI& p) const -> PointI { return {x - p.x, y - p.y}; }
    auto operator*(i128 k) const -> PointI { return {x * k, y * k}; }
};
auto operator*(i128 k, const PointI& p) -> PointI { return p * k; }
auto dot(const PointI& a, const PointI& b) -> i128 { return a.x * b.x + a.y * b.y; }
auto cross(const PointI& a, const PointI& b) -> i128 { return a.x * b.y - a.y * b.x; };
auto norm2(const PointI& p) -> i128 { return dot(p, p); }
std::istream& operator>>(std::istream& is, i128& val) {
    std::string s;
    bool flag = true;
    is >> s, val = 0;
    if (s[0] == '-') flag = false, val = std::stoi(s.substr(0, 2)), s = s.substr(2);
    for (char& c : s) val = val * 10 + (c - '0') * (!flag ? -1 : 1);
    return is;
}
std::ostream& operator<<(std::ostream& os, i128 val) {
    if (val < 0) os << "-", val = -val;
    if (val > 9) os << val / 10;
    os << static_cast<char>(val % 10 + '0');
    return os;
}
struct Frac {
    i128 p, q;
    bool operator<(const Frac& f) const { return p * f.q < q * f.p; };
    bool operator==(const Frac& f) const { return p * f.q == q * f.p; }
};
void solve() {
    ll n, x, y;
    cin >> n;
    vector<PointI> ma;
    rep(i, 0, n - 1) {
        cin >> x >> y;
        ma.emplace_back(x, y);
    }
    ma.push_back(ma[0]);
    vector<pair<Frac, ll>> events;
    rep(i, 0, n - 1) {
        PointI a = ma[i], b = ma[i + 1];
        PointI v = b - a;
        auto val = -dot(a, v);
        Frac d;
        if (val <= 0)
            d = {norm2(a), 1};
        else if (val >= norm2(v))
            d = {norm2(b), 1};
        else {
            auto c = cross(a, b);
            d = {c * c, norm2(v)};
        }
        events.emplace_back(d, 2);
        events.emplace_back(Frac(norm2(a), 1), -1);
        events.emplace_back(Frac(norm2(b), 1), -1);
    }
    ll m = sz(events);
    sort(all(events), [&](const pair<Frac, ll>& x, const pair<Frac, ll>& y) -> bool { return x.first < y.first; });
    ll ans = 0, cur = 0;
    ll i = 0;
    while (i <= m - 1) {
        ll j = i;
        ll val = 0;
        while (j <= m - 1 && events[j].first == events[i].first) {
            val += events[j].second;
            j++;
        }
        cur += val;
        ans = max(ans, cur);
        i = j;
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
