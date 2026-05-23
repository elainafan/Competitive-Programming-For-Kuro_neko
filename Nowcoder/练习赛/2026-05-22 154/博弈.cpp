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
    int n;
    cin >> n;
    vl a(n);
    ll tem = 0;
    rep(i, 0, n - 1) {
        cin >> a[i];
        a[i] = a[i] % 2;
        tem += a[i];
    }
    if (n == 1 || tem > n - tem) {
        cout << "Alice" << endl;
        return;
    }
    vl dp(n);
    dp[0] = (a[0] == 0 ? 1 : -1);
    for (int i = 2; i <= n - 1; i += 2) dp[i] = max(dp[i - 2] + (a[i] == 0 ? 1 : -1), 1LL * (a[i] == 0 ? 1 : -1));
    dp[1] = (a[1] == 0);
    for (int i = 3; i <= n - 1; i += 2) dp[i] = max(dp[i - 2] + (a[i] == 0 ? 1 : -1), 1LL * (a[i] == 0 ? 1 : -1));
    int tem2 = *max_element(all(dp));
    cout << (tem + tem2 > n - tem - tem2 ? "Alice" : "Bob") << endl;
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
