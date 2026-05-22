#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    ll n, k;
    cin >> n >> k;
    if (n < k) {
        cout << -1 << endl;
        return;
    }
    int ans = INT_MAX;
    map<ll, int> ma;
    auto dfs = [&](this auto&& dfs, ll x, int t) {
        if (ma.count(x)) return;
        if (x < k) return;
        ma[x]++;
        if (x == k) {
            ans = min(ans, t);
            return;
        }
        if (x % 2 == 0)
            dfs(x / 2, t + 1);
        else {
            dfs(x / 2, t + 1);
            dfs(x / 2 + 1, t + 1);
        }
        return;
    };
    dfs(n, 0);
    if (ans == INT_MAX)
        cout << -1 << endl;
    else
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