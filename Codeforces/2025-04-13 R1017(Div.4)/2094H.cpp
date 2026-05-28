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
constexpr int MX = 1e5 + 5;
vector<int> divisors[MX];
auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();
void solve() {
    ll n, q, l, r, k;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) { cin >> a[i]; }
    ll maxx = *max_element(all(a));
    map<ll, vl> tem;
    rep(i, 0, n - 1) tem[a[i]].push_back(i);
    rep(i, 0, q - 1) {
        cin >> k >> l >> r;
        l--, r--;
        int tem2 = l;
        ll ans = 0;
        vector<pll> tem4;
        for (auto& p : divisors[k]) {
            if (p > maxx) break;
            if (tem[p].empty()) continue;
            int tem3 = ranges::lower_bound(tem[p], tem2) - tem[p].begin();
            if (tem3 == sz(tem[p])) continue;
            if (tem[p][tem3] > r) continue;
            tem4.emplace_back(tem[p][tem3], p);
        }
        ranges::sort(tem4);
        for (auto& [x, y] : tem4) {
            if (x < tem2) continue;
            if (k % y != 0) continue;
            ans += k * (x - tem2);
            while (k % y == 0) k /= y;
            ans += k;
            tem2 = x + 1;
            if (k == 1) break;
        }
        if (tem2 <= r) ans += k * (r - tem2 + 1);
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
