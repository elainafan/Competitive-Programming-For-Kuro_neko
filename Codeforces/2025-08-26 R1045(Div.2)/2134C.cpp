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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    if (n == 2) {
        cout << max(0LL, a[0] - a[1]) << endl;
        return;
    }
    ll ans = 0;
    for (ll i = 2; i <= n - 1; i += 2) {
        ll tem = a[i - 2] + a[i];
        if (tem > a[i - 1]) {
            ll tem2 = tem - a[i - 1];
            ans += tem2;
            ll tem3 = min(tem2, a[i]);
            a[i] -= tem3;
            a[i - 2] -= tem2 - tem3;
        }
    }
    if (n % 2 == 0 && a[n - 2] > a[n - 1]) ans += a[n - 2] - a[n - 1];
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
