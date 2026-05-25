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
const ll MOD = 998244353;
void solve() {
    int n, x, y;
    cin >> n;
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    int idx = -1;
    rep(i, 0, n - 1) {
        if (sz(ma[i]) == 1) idx = max(idx, i);
    }
    if (idx == n - 1) {
        cout << 1 << endl;
        return;
    }
    vi pa(n, -1);
    pa[n - 1] = n - 1;
    queue<int> q;
    q.push(n - 1);
    vi tem;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        tem.push_back(node);
        for (int& p : ma[node]) {
            if (pa[p] >= 0) continue;
            pa[p] = node;
            q.push(p);
        }
    }
    vi maxx(n, -1), maxx2(n, -1);
    frep(i, n - 1, 0) {
        int tem2 = tem[i];
        maxx[tem2] = tem2;
        for (int& p : ma[tem2]) {
            if (pa[p] == tem2) {
                maxx[tem2] = max(maxx[tem2], maxx[p]);
                maxx2[tem2] = max(maxx2[tem2], maxx[p]);
            }
        }
    }
    vl dp(n), pre(n);
    rep(i, 0, n - 2) {
        ll tem2 = 0;
        if (maxx2[i] < i) {
            ll r = (i >= 1 ? pre[i - 1] : 0);
            ll l = (maxx2[i] >= 0 ? pre[maxx2[i]] : 0);
            tem2 = (r - l + MOD) % MOD;
        }
        if (i == idx) tem2 = (tem2 + 1) % MOD;
        dp[i] = tem2;
        if (i == 0)
            pre[i] = dp[i];
        else
            pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    int pm1 = -1, pm2 = -1;
    for (int& p : ma[n - 1]) {
        if (pa[p] == n - 1) {
            if (maxx[p] > pm1) {
                pm2 = pm1;
                pm1 = maxx[p];
            } else if (maxx[p] > pm2) {
                pm2 = maxx[p];
            }
        }
    }
    ll tem2 = (pm2 >= 0 ? pre[pm2] : 0);
    cout << (pre[n - 2] - tem2 + MOD) % MOD << endl;
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