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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
const int MOD = 998244353;
const int MX = 3e5 + 1;
int cnt[MX];
auto init = [] {
    cnt[0] = 1;
    rep(i, 1, MX - 1) { cnt[i] = cnt[i - 1] * 2 % MOD; }
    return 0;
}();
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll f = 0, g = 0;
    ll pre = 0;
    rep(i, 0, n - 1) {
        if (s[i] == '(') {
            ans += cnt[i];
            ans %= MOD;
            pre++;
            f = (2 * f + g + 1) % MOD;
        } else {
            pre--;
            ans += (f + g + 1) % MOD;
            ans %= MOD;
            g = (2 * g + f + 1) % MOD;
        }
        if (pre < 2) f = 0;
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
