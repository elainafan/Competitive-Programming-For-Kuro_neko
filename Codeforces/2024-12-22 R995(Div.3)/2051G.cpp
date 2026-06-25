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
    ll n, q, x;
    char c;
    cin >> n >> q;
    int mask = (1LL << n);
    vvl dp(mask, vl(n, LLONG_MAX / 3));
    vl add(n), sub(n);
    vl add2(n);
    vvl dis(n, vl(n, 1));
    rep(i, 0, q - 1) {
        cin >> x >> c;
        x--;
        if (c == '+') {
            add[x]++;
            add2[x] = max(add2[x], add[x]);
            rep(j, 0, n - 1) {
                if (j == x) continue;
                dis[x][j] = max(dis[x][j], add[x] - sub[j] + 1);
            }
        } else {
            sub[x]++;
        }
    }
    rep(i, 0, n - 1) dp[(1LL << i)][i] = 1;
    dp[0][0] = 0;
    rep(i, 1, mask - 1) {
        rep(j, 0, n - 1) {
            if (dp[i][j] == LLONG_MAX / 3) continue;
            if (!((i >> j) & 1)) continue;
            rep(v, 0, n - 1) {
                if (i >> v & 1) continue;
                dp[i | (1 << v)][v] = min(dp[i | (1 << v)][v], dp[i][j] + dis[j][v]);
            }
        }
    }
    ll ans = LLONG_MAX;
    rep(i, 0, n - 1) ans = min(ans, dp[mask - 1][i] + add2[i]);
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
