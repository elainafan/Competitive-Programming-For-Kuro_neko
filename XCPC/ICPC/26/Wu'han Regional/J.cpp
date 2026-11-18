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
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    map<ll, ll> ma1, ma2;
    rep(i, 0, n - 1) ma1[a[i]]++, ma2[b[i]]++;
    for (auto& [x, y] : ma2) {
        if (x >= n + 1 && (!ma1.count(x) || ma1[x] < y)) {
            cout << "NO" << endl;
            return;
        }
    }
    vl cnt0(n + 1), cnt1(n + 1);
    rep(i, 0, n - 1) {
        if (a[i] <= n)
            cnt0[a[i]]++;
        else
            cnt0[0]++;
    }
    rep(i, 0, n - 1) {
        if (b[i] <= n) cnt1[b[i]]++;
    }
    vector<pll> tem;
    rep(i, 2, n) {
        if (cnt1[i] == 0)
            continue;
        else
            tem.emplace_back(i - cnt1[i], i);
    }
    sort(all(tem));
    ll cur = cnt1[0] + cnt1[1];
    for (auto& [x, y] : tem) {
        if (cur >= x)
            cur += cnt1[y];
        else {
            if (cnt0[y] < cnt1[y]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
