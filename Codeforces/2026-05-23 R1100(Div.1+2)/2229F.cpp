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
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::sort(a);
    ll tem = a[n - 1];
    ll tot = 0;
    rep(i, 0, n - 2) tot += a[i];
    n--;
    auto check = [&](ll mid) -> bool {
        int mask = (1 << n);
        vl dp(mask, -1);
        vl fdp(mask, -1);
        dp[0] = 0, fdp[0] = 0;
        rep(i, 0, mask - 1) {
            if (dp[i] == -1) continue;
            rep(j, 0, n - 1) {
                if ((i >> j) & 1) continue;
                ll tem = dp[i], tem2 = fdp[i];
                if (tem2 + a[j] >= mid) {
                    tem++, tem2 = 0;
                } else
                    tem2 += a[j];
                if (tem > dp[(i | (1 << j))]) {
                    dp[(i | (1 << j))] = tem;
                    fdp[(i | (1 << j))] = tem2;
                } else if (tem == dp[(i | (1 << j))] && tem2 > fdp[(i | (1 << j))]) {
                    fdp[(i | (1 << j))] = tem2;
                }
                if (dp[(i | (1 << j))] >= k) return true;
            }
        }
        return dp[mask - 1] >= k;
    };
    ll l = 0, r = tot / k, ans = 0, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << tem + ans << endl;
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