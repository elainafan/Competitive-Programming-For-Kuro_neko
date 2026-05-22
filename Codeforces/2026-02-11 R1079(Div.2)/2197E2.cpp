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
vi ask(int l) {
    cout << "? " << l << '\n';
    cout.flush();
    int q;
    cin >> q;
    vi res(q);
    rep(i, 0, q - 1) cin >> res[i];
    return res;
}
void report(vector<pii> &res) {
    cout << "! " << sz(res) << '\n';
    rep(i, 0, sz(res) - 1) { cout << res[i].first << ' ' << res[i].second << '\n'; }
    cout.flush();
}
void solve() {
    int n;
    cin >> n;
    vector<pii> res;
    vector<bool> pd(n, false);
    vl dp(n, 1);
    vi tem;
    ll cnt = 1;
    rep(i, 0, n - 1) {
        cnt += 1LL * dp[i];
        pd[i] = true;
        while (true) {
            tem = ask(cnt);
            if (sz(tem) <= 1) {
                break;
            }
            rep(j, 0, sz(tem) - 2) dp[tem[j] - 1] += dp[tem.back() - 1];
            res.emplace_back(tem[sz(tem) - 2], tem[sz(tem) - 1]);
            if (pd[tem.back() - 1]) {
                cnt += dp[tem.back() - 1];
                continue;
            }
            pd[tem.back() - 1] = true;
            cnt++;
        }
    }
    report(res);
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
