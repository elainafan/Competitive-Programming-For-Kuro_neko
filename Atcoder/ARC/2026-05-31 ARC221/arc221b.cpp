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
ll MOD;
constexpr int MX = 705;
ll c[MX][MX];  // 即为C(n,m),从n个数中取m个数
void init() {
    for (int i = 0; i < MX; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    return;
};  // 适用于MX较小的情况

namespace Stirling {
/*
用法：

1. 下降幂
   falling_power(x, k) = x^{\underline{k}} = x(x-1)...(x-k+1) mod MOD
   例：falling_power(n, k) 表示从 n 个不同元素中有顺序选 k 个，即 A(n,k)。

2. 第一类斯特林数
   auto s1 = first_unsigned(n);
   s1[i][j] = c(i,j)，无符号第一类斯特林数，表示 i 个元素分成 j 个非空圆排列的方案数。

   auto ss1 = first_signed(n);
   ss1[i][j] = s(i,j)，带符号第一类斯特林数，满足：
   x^{\underline{i}} = sum_{j=0}^i s(i,j) x^j
   若需要无符号值，则 c(i,j) = (-1)^{i-j} s(i,j)。

3. 第二类斯特林数
   auto s2 = second(n);
   s2[i][j] = S(i,j)，表示 i 个有标号元素分成 j 个非空无标号集合的方案数。
   常见公式：
   x^i = sum_{j=0}^i S(i,j) x^{\underline{j}}

复杂度：
   first_unsigned / first_signed / second 都是 O(n^2) 预处理，O(1) 查询。
   falling_power 是 O(k)。
*/

ll norm(ll x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

// 下降幂 x^{\underline{k}} = x(x-1)...(x-k+1)
ll falling_power(ll x, int k) {
    ll res = 1;
    for (int i = 0; i < k; i++) {
        res = res * norm(x - i) % MOD;
    }
    return res;
}

// 无符号第一类斯特林数 c(n,k)：n个元素分成k个圆排列
// c(n,k)=c(n-1,k-1)+(n-1)c(n-1,k)
vector<vector<ll>> first_unsigned(int n) {
    vector<vector<ll>> s(n + 1, vector<ll>(n + 1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = (s[i - 1][j - 1] + (i - 1LL) * s[i - 1][j]) % MOD;
        }
    }
    return s;
}

// 带符号第一类斯特林数 s(n,k)：x^{\underline{n}} = sum s(n,k)x^k
// s(n,k)=s(n-1,k-1)-(n-1)s(n-1,k)
vector<vector<ll>> first_signed(int n) {
    vector<vector<ll>> s(n + 1, vector<ll>(n + 1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = norm(s[i - 1][j - 1] - (i - 1LL) * s[i - 1][j]);
        }
    }
    return s;
}

// 第二类斯特林数 S(n,k)：n个有标号元素分成k个非空无标号集合
// S(n,k)=S(n-1,k-1)+kS(n-1,k)
vector<vector<ll>> second(int n) {
    vector<vector<ll>> s(n + 1, vector<ll>(n + 1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = (s[i - 1][j - 1] + 1LL * j * s[i - 1][j]) % MOD;
        }
    }
    return s;
}
}  // namespace Stirling

void solve() {
    ll n;
    cin >> n >> MOD;
    init();
    auto s2 = Stirling::second(n);
    vl tem(n * n + 1);
    tem[0] = 1;
    rep(i, 1, n * n) tem[i] = tem[i - 1] * 2 % MOD;
    vl dp(n + 1);
    dp[0] = 1;
    rep(i, 1, n) {
        rep(j, 1, i) {
            ll tem2 = 0;
            rep(v, 1, j) {
                if (v % 2 == 1)
                    tem2 = (tem2 + s2[j][v] * tem[(i - j) * v] % MOD) % MOD;
                else
                    tem2 = (tem2 - s2[j][v] * tem[(i - j) * v] % MOD + MOD) % MOD;
            }
            dp[i] = (dp[i] + tem2 * c[i][j] % MOD * dp[i - j] % MOD) % MOD;
        }
    }
    ll ans = 0;
    rep(i, 0, n) ans = (ans + c[n][i] * dp[i] % MOD) % MOD;
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
