#include <bits/stdc++.h>
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
vector<int> kmp(const vi& pattern) {
    int m = pattern.size();
    vector<int> pi(m);
    int cnt = 0;
    for (int i = 1; i < m; i++) {
        int b = pattern[i];
        while (cnt && pattern[cnt] != b) cnt = pi[cnt - 1];
        if (pattern[cnt] == b) cnt++;
        pi[i] = cnt;
    }
    return pi;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vvi border(n + 1);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) {
        vi tem(a.begin() + i, a.end());
        auto tem2 = kmp(tem);
        border[i + 1] = tem2;
    }
    vi dp(n + 1);
    dp[0] = 1;
    rep(i, 1, n) {
        rep(j, 0, i - 1) {
            if (border[j + 1][i - j - 1])
                continue;
            else {
                dp[i] += dp[j] % MOD;
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
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
