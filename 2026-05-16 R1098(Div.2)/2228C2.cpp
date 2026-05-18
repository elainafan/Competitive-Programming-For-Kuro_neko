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
    ll n, a;
    cin >> a >> n;
    string s = to_string(a);
    int m = sz(s);
    vl d(n);
    rep(i, 0, n - 1) cin >> d[i];
    ranges::sort(d);
    ll ans = LLONG_MAX;
    vl tem(m + 1, 1);
    rep(i, 1, m) tem[i] = tem[i - 1] * 10;
    if (m > 1) {
        ll tem2 = 0;
        rep(i, 1, m - 1) tem2 = tem2 * 10 + d[n - 1];
        ans = min(ans, abs(tem2 - a));
    }
    int idx = -1;
    rep(i, 0, n - 1) {
        if (d[i] != 0) {
            idx = i;
            break;
        }
    }
    if (idx != -1) {
        ll tem2 = d[idx];
        rep(i, 2, m + 1) {
            if (tem2 > (LLONG_MAX - d[0]) / 10) {
                tem2 = LLONG_MAX;
                break;
            }
            tem2 = tem2 * 10 + d[0];
        }
        if (tem2 != LLONG_MAX) ans = min(ans, abs(tem2 - a));
    }
    vector<array<int, 3>> vis(m + 1);
    vector<array<ll, 3>> ma(m + 1);
    auto dfs = [&](this auto&& dfs, int pos, int st) -> ll {
        if (pos == m) return 0;
        if (vis[pos][st]) return ma[pos][st];
        vis[pos][st] = 1;
        ll res = LLONG_MAX;
        int tem2 = s[pos] - '0';
        rep(i, 0, n - 1) {
            if (pos == 0 && m > 1 && d[i] == 0) continue;
            ll temp = 0;
            int tx = st;
            if (st == 0) {
                if (d[i] < tem2) {
                    tx = 1;
                    temp += (tem2 - d[i]) * tem[m - pos - 1];
                } else if (d[i] > tem2) {
                    tx = 2;
                    temp += (d[i] - tem2) * tem[m - pos - 1];
                }
            } else if (st == 1) {
                temp += (tem2 - d[i]) * tem[m - pos - 1];
            } else {
                temp += (d[i] - tem2) * tem[m - pos - 1];
            }
            temp += dfs(pos + 1, tx);
            res = min(res, temp);
        }
        ma[pos][st] = res;
        return res;
    };
    cout << min(ans, dfs(0, 0)) << endl;
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