#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, q, x;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl res;
    res.push_back(*max_element(all(a)) - *min_element(all(a)));
    ll cnt = 1;
    while (true) {
        priority_queue<ll, vl, less<>> q;
        ll tot = 0;
        rep(i, 0, n - 1) {
            rep(j, i + 1, n - 1) {
                q.push((a[i] ^ a[j]));
                tot++;
                if (tot > n) q.pop();
            }
        }
        vl tem;
        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            tem.push_back(node);
        }
        if (tem[0] == tem[n - 1]) break;
        res.push_back(tem[0] - tem[n - 1]);
        a = tem;
        cnt++;
    }
    rep(_, 0, q - 1) {
        cin >> x;
        cout << (x <= cnt - 1 ? res[x] : 0) << endl;
    }
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
