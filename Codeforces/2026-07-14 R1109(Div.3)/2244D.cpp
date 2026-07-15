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
    ll n, m;
    cin >> n >> m;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl b(m);
    rep(i, 0, m - 1) cin >> b[i], b[i]--;
    ranges::sort(b);
    ll tem = 0;
    ll ans = 0;
    rep(i, b[m - 1] + 1, n - 1) ans += a[i];
    ll tot = 0;
    rep(i, 0, b[0]) { tot += a[i]; }
    ans += abs(tot);
    rep(i, 1, m - 1) {
        ll tot = 0;
        rep(j, b[i - 1] + 1, b[i]) tot += a[j];
        ans += abs(tot);
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
