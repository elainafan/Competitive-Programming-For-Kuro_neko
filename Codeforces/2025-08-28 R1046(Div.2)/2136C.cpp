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
    vl a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vl dp(n + 1);
    vector<deque<int>> q(n + 1);
    ll ans = 0;
    rep(i, 1, n) {
        dp[i] = dp[i - 1];
        q[a[i]].push_back(i);
        while (sz(q[a[i]]) > a[i]) {
            q[a[i]].pop_front();
        }
        if (sz(q[a[i]]) == a[i]) {
            dp[i] = max(dp[i], dp[q[a[i]].front() - 1] + a[i]);
        }
        ans = max(ans, dp[i]);
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
