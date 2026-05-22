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
vl primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    vi tem(n);
    auto lcm = [&](ll x, ll y) -> ll {
        ll tem = __gcd(x, y);
        return x / tem * y;
    };
    rep(i, 0, n - 1) {
        if (i == 0) {
            tem[i] = __gcd(a[i], a[i + 1]);
        } else if (i == n - 1) {
            tem[i] = __gcd(a[i], a[i - 1]);
        } else {
            tem[i] = lcm(__gcd(a[i], a[i + 1]), __gcd(a[i], a[i - 1]));
        }
    }
    vvl tem2(n);
    rep(i, 0, n - 1) {
        tem2[i].push_back(a[i]);
        if (tem[i] <= b[i] && tem[i] != a[i]) {
            tem2[i].push_back(tem[i]);
        }
        if (tem[i] == a[i]) {
            for (auto& p : primes) {
                if (1LL * p * tem[i] <= b[i]) {
                    tem2[i].push_back(1LL * p * tem[i]);
                } else
                    break;
            }
        }
        sort(all(tem2[i]));
        tem2[i].erase(unique(all(tem2[i])), tem2[i].end());
    }
    vvi dp(n, vi(26, INT_MIN));
    rep(i, 0, sz(tem2[0]) - 1) dp[0][i] = (tem2[0][i] == a[0] ? 0 : 1);
    rep(i, 1, n - 1) {
        rep(j, 0, sz(tem2[i]) - 1) {
            int tem3 = (tem2[i][j] == a[i] ? 0 : 1);
            rep(k, 0, sz(tem2[i - 1]) - 1) {
                if (__gcd(tem2[i][j], tem2[i - 1][k]) == __gcd(a[i], a[i - 1])) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + tem3);
                }
            }
        }
    }
    int ans = 0;
    rep(i, 0, sz(tem2[n - 1]) - 1) ans = max(ans, dp[n - 1][i]);
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
