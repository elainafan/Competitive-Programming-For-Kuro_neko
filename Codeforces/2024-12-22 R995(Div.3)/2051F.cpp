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
using i128 = __int128_t;
void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vl a(q);
    rep(i, 0, q - 1) cin >> a[i];
    vl res(q);
    vector<pll> tem;
    tem.emplace_back(m, m);
    rep(i, 0, q - 1) {
        vector<pll> ntem;
        for (auto& [x, y] : tem) {
            if (y < a[i])
                ntem.emplace_back(x, y + 1);
            else if (x > a[i])
                ntem.emplace_back(x - 1, y);
            else {
                ntem.emplace_back(1, 1);
                ntem.emplace_back(n, n);
                if (x < a[i]) ntem.emplace_back(x, a[i]);
                if (a[i] < y) ntem.emplace_back(a[i], y);
            }
        }
        sort(all(ntem), [&](const pll& x, const pll& y) { return x.first < y.first; });
        tem.clear();
        for (auto& [x, y] : ntem) {
            if (tem.empty() || x > tem.back().second)
                tem.emplace_back(x, y);
            else
                tem.back().second = max(tem.back().second, y);
        }
        ll ans = 0;
        for (auto& [x, y] : tem) ans += y - x + 1;
        res[i] = ans;
    }
    rep(i, 0, q - 1) cout << res[i] << ' ';
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
