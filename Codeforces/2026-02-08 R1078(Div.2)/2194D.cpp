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
void solve() {
    int n, m;
    cin >> n >> m;
    vvi ma(n, vi(m));
    int tot = 0;
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cin >> ma[i][j];
            if (ma[i][j] == 1) tot++;
        }
    }
    cout << 1LL * (tot / 2) * (tot - tot / 2) << endl;
    vi dp(m);
    int tem = 0;
    int idx = 0;
    rep(j, 0, m - 1) {
        if (tem == tot / 2) {
            dp[j] = n;
            continue;
        }
        frep(i, n - 1, 0) {
            tem += ma[i][j];
            dp[j] = i;
            if (tem == tot / 2) break;
        }
    }
    string ans = "";
    rep(i, 0, m - 1) {
        if (i > 0) {
            rep(j, 1, dp[i] - dp[i - 1]) { ans += 'D'; }
        } else {
            rep(j, 1, dp[i]) { ans += 'D'; }
        }
        ans += 'R';
    }
    rep(i, 1, n - dp[m - 1]) { ans += 'D'; }
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
