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
    if (n == 1) {
        cout << abs(a[0]) << endl;
        return;
    }
    vl pre(n);
    vl suf(n);
    pre[0] = (a[0] >= 0 ? a[0] : 0);
    rep(i, 1, n - 1) pre[i] = pre[i - 1] + (a[i] >= 0 ? a[i] : 0);
    suf[n - 1] = (a[n - 1] < 0 ? -a[n - 1] : 0);
    frep(i, n - 2, 0) suf[i] = suf[i + 1] + (a[i] < 0 ? -a[i] : 0);
    ll ans = 0;
    rep(i, 0, n - 2) { ans = max(ans, pre[i] + suf[i + 1]); }
    ans = max(ans, pre[n - 1]);
    ans = max(ans, suf[0]);
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
