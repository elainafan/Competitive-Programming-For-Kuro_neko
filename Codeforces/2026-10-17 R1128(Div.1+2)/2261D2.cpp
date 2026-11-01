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
using ull = unsigned long long;
vector<ull> xor_hash(ll n, const vector<pll>& seg) {
    vector<ull> h(n + 2);
    for (auto [l, r] : seg) {
        ull v = rng();
        v = (v << 32) | rng();
        h[l] ^= v;
        h[r + 1] ^= v;  // 进入区间时加入，离开时消去
    }
    rep(i, 1, n) h[i] ^= h[i - 1];
    h.pop_back();
    return h;
}

pair<vi, int> calc(const vector<ull>& h) {
    int n = sz(h) - 1, cnt = 0;
    unordered_map<ull, int> ma;
    ma.reserve(n);
    vi id(n + 1);
    rep(i, 1, n) {
        auto [it, ok] = ma.emplace(h[i], cnt);
        if (ok) cnt++;
        id[i] = it->second;
    }
    return {move(id), cnt};
}
const ll LOG = 20;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> ma(m);
    rep(i, 0, m - 1) cin >> ma[i].first >> ma[i].second;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (m == 0) {
        cout << (n + 1) / 2 << endl;
        rep(i, 0, (n + 1) / 2 - 1) {
            if (i == 0) {
                if (n == 2)
                    cout << "1 1" << endl;
                else
                    cout << "1 2" << endl;
                continue;
            }
            cout << 2 * i << ' ' << min(2 * i + 2, n - 1 + (n % 2)) << endl;
        }
        return;
    }
    auto [ma2, tot] = calc(xor_hash(n, ma));
    ma2.erase(ma2.begin());
    rep(i, 0, n - 1) ma2.push_back(ma2[i]);
    vl pa(2 * n + 1, 2 * n), las(tot, 2 * n);
    vvl up(LOG, vl(2 * n + 1, 2 * n));
    frep(i, 2 * n - 1, 0) {
        pa[i] = min(pa[i + 1], las[ma2[i]]);
        las[ma2[i]] = i;
    }
    rep(i, 0, 2 * n - 1) up[0][i] = pa[i];
    rep(j, 1, LOG - 1) { rep(i, 0, 2 * n - 1) up[j][i] = up[j - 1][up[j - 1][i]]; }
    ll mn = LLONG_MAX / 3, idx = -1;
    rep(i, 0, n - 1) {
        ll cur = i, cnt = 1;
        frep(j, LOG - 1, 0) {
            if (up[j][cur] < i + n) {
                cur = up[j][cur];
                cnt += (1 << j);
            }
        }
        if (cnt < mn) mn = cnt, idx = i;
    }
    if (mn == 1) {
        cout << 0 << endl;
        return;
    }
    cout << (mn + 1) / 2 << endl;
    vector<pll> tem;
    ll cur = idx;
    while (cur < idx + n) {
        tem.emplace_back(cur, min(idx + n - 1, pa[cur] - 1));
        cur = pa[cur];
    }
    rep(i, 0, (mn + 1) / 2 - 1) {
        ll l, r;
        if (i == 0) {
            l = tem[0].first, r = tem[mn == 2 ? 0 : 1].second;
        } else {
            l = tem[2 * i - 1].first, r = tem[min(2 * i + 1, mn - 1 - (mn % 2 == 0))].second;
        }
        cout << (l / n == r / n ? l % n + 1 : r % n + 2) << ' ' << (l / n == r / n ? r % n + 1 : l % n) << endl;
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
