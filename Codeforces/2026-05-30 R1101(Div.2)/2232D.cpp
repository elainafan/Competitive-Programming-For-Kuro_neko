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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) {
        if (a[i] > i) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<trl> res;
    vl tem(n);
    auto dfs = [&](this auto&& dfs, ll t, ll x, ll y, ll d) -> void {
        if (t == 0) return;
        ll tem2 = (d == t ? x : y);
        if (tem[t - 1] != tem2) {
            dfs(t - 1, tem[t - 1], 3 - tem[t - 1] - tem2, a[t - 1]);
            res.emplace_back(t, tem[t - 1] + 1, tem2 + 1);
            tem[t - 1] = tem2;
        }
        dfs(t - 1, x, y, min(d, t - 1));
    };
    dfs(n, 2, 1, n);
    cout << "YES" << endl;
    cout << sz(res) << endl;
    for (auto& [x, y, z] : res) cout << x << ' ' << y << ' ' << z << endl;
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