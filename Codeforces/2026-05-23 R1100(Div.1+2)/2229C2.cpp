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
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl res;
    ll mixx = LLONG_MAX;
    vl pre(n + 1);
    vl suf(n + 2);
    rep(i, 1, n) pre[i] = pre[i - 1] + abs(a[i - 1]);
    frep(i, n, 1) suf[i] = suf[i + 1] + a[i - 1];
    ll maxx = suf[1];
    int idx = -1;
    rep(i, 1, n) {
        if (a[i - 1] > 0) {
            if (pre[i - 1] - a[i - 1] + suf[i + 1] > maxx) {
                maxx = pre[i - 1] - a[i - 1] + suf[i + 1];
                idx = i;
            }
        }
    }
    if (idx == -1) {
        cout << 0 << endl;
        cout << endl;
        return;
    }
    vl dp(n + 2);
    rep(i, 1, idx - 1) dp[i] = (a[i - 1] < 0);
    dp[idx] = 1;
    vi tem;
    rep(i, 1, n) {
        if (dp[i] != dp[i + 1]) tem.push_back(i);
    }
    if (sz(tem) % 2 == 1) {
        for (int i = 0; i <= sz(tem) - 2; i += 2) {
            res.push_back(tem[i + 1]);
            res.push_back(tem[i]);
        }
    } else {
        res.push_back(tem[0]);
        for (int i = 1; i <= sz(tem) - 2; i += 2) {
            res.push_back(tem[i + 1]);
            res.push_back(tem[i]);
        }
    }
    res.push_back(tem[sz(tem) - 1]);
    cout << sz(res) << endl;
    rep(i, 0, sz(res) - 1) cout << res[i] << ' ';
    cout << endl;
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