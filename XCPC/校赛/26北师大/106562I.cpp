#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, t;
    cin >> n >> t;
    vector<array<ll, 3>> ma(n);
    rep(i, 0, n - 1) cin >> ma[i][0] >> ma[i][1] >> ma[i][2];
    sort(all(ma), [&](const array<ll, 3>& x, const array<ll, 3>& y) { return x[1] * y[2] > y[1] * x[2]; });
    vl dp(t + 1, LLONG_MIN / 3);
    dp[0] = 0;
    rep(i, 0, n - 1) {
        frep(j, t, ma[i][2]) { dp[j] = max(dp[j], dp[j - ma[i][2]] + ma[i][0] - ma[i][1] * j); }
    }
    cout << *max_element(all(dp)) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
