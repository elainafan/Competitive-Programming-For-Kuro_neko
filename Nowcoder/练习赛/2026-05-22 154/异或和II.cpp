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
void solve() {
    ll n, q, op, x, y;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl cnt(31);
    rep(i, 0, n - 1) { rep(j, 0, 30) cnt[j] += (a[i] >> j & 1); }
    auto calc = [&](int x, int y) -> int {
        if (x == 0)
            return 0;
        else
            return !((y & (x - 1)) == y);
    };
    rep(i, 0, q - 1) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            x--;
            rep(j, 0, 30) cnt[j] -= (a[x] >> j & 1);
            a[x] = y;
            rep(j, 0, 30) cnt[j] += (a[x] >> j & 1);
        } else {
            cin >> x;
            ll ans = 0;
            rep(j, 0, 30) { ans += 1LL * (1 << j) * (calc(n, x) ^ calc(n - cnt[j], x)); }
            cout << ans << endl;
        }
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
