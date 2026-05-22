#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<array<ll, 2>, 4>> dp(n + 1);
    dp[0][0][0] = 1;
    for (auto c : s) {
        auto ndp = dp;
        for (int i = 0; i <= n; i++) {
            int tem = i + (c == ')' ? -1 : 1);
            if (tem < 0 || tem > n) continue;
            for (int j = 3; j >= 0; j--) {
                if (j < 3 && c == ")(("[j]) {
                    ndp[tem][j + 1][1] += dp[i][j][0] % MOD;
                    ndp[tem][j + 1][1] %= MOD;
                    ndp[tem][j + 1][1] += dp[i][j][1] % MOD;
                    ndp[tem][j + 1][1] %= MOD;
                    ndp[tem][j + 1][0] += dp[i][j][0] % MOD;
                    ndp[tem][j + 1][0] %= MOD;
                } else {
                    ndp[tem][j][1] += dp[i][j][0] % MOD;
                    ndp[tem][j][1] %= MOD;
                    ndp[tem][j][1] += dp[i][j][1] % MOD;
                    ndp[tem][j][1] %= MOD;
                    ndp[tem][j][0] += dp[i][j][0] % MOD;
                    ndp[tem][j][0] %= MOD;
                }
            }
        }
        dp = ndp;
    }
    cout << (dp[0][3][1] - 2 * dp[0][3][0] % MOD + MOD) % MOD << endl;
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