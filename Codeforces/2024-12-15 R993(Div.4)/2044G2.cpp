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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i], a[i]--;
    vvl ma(n);
    vl deg(n);
    rep(i, 0, n - 1) {
        ma[i].push_back(a[i]);
        deg[a[i]]++;
    }
    queue<ll> q;
    vl dp(n, 1);
    rep(i, 0, n - 1) {
        if (deg[i] == 0) q.push(i);
    }
    ll ans = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        ans = max(ans, dp[node]);
        for (auto& p : ma[node]) {
            dp[p] += dp[node];
            if (--deg[p] == 0) q.push(p);
        }
    }
    cout << ans + 2 << endl;
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
