#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define endl '\n'
using namespace std;
constexpr int MOD = 998244353;
using matrix = vector<vector<ll>>;
matrix mul(matrix& a, matrix& b) {
    int n = a.size(), m = b[0].size();
    matrix c = matrix(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            if (a[i][k] == 0) continue;
            for (int j = 0; j < m; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}
matrix pow_mul(matrix a, int n, matrix& f0) {
    matrix res = f0;
    while (n) {
        if (n & 1) res = mul(a, res);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<string> ma(k);
    rep(i, 0, k - 1) cin >> ma[i];
    auto check = [](const string& x, const string& y) -> bool {
        if (sz(x) > sz(y)) return false;
        int n = sz(x), m = sz(y);
        rep(i, 0, n - 1) {
            if (x[i] != y[m - n + i]) return false;
        }
        return true;
    };
    auto check2 = [&](const string& x) -> bool {
        for (auto& p : ma) {
            if (check(p, x)) return true;
        }
        return false;
    };
    int cnt = 0;
    map<string, int> ma2;
    ma2[""] = cnt++;
    rep(i, 0, k - 1) {
        rep(j, 1, sz(ma[i])) {
            if (ma2.count(ma[i].substr(0, j))) continue;
            ma2[ma[i].substr(0, j)] = cnt++;
        }
    }
    auto calc = [&](const string& x) {
        string tem = "";
        for (auto& [a, b] : ma2) {
            if (check(a, x)) {
                if (sz(a) > sz(tem)) {
                    tem = a;
                }
            }
        }
        return ma2[tem];
    };
    int m = sz(ma2);
    matrix dp(m, vl(m, 0));
    matrix f0(m, vl(1, 0));
    f0[ma2[""]][0] = 1;
    for (auto& [a, b] : ma2) {
        if (check2(a)) continue;
        rep(i, 0, 25) {
            char c = (char)('a' + i);
            string tem = a;
            tem.push_back(c);
            if (check2(tem)) continue;
            int tem2 = calc(tem);
            dp[tem2][b] = (dp[tem2][b] + 1) % MOD;
        }
    }
    matrix fn = pow_mul(dp, n, f0);
    ll ans = 0;
    for (auto& [a, b] : ma2) {
        if (!check2(a)) {
            ans = (ans + fn[b][0]) % MOD;
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}