#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, op, x, y;
    cin >> n;
    vector<pll> ma;
    vl ma2;
    rep(i, 0, n - 1) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            ma2.push_back(x);
        } else {
            cin >> x >> y;
            if (x >= y) {
                ma2.push_back(x), ma2.push_back(y);
            } else
                ma.emplace_back(x, y);
        }
    }
    ll ans1 = 0, ans2 = 0;
    sort(all2(ma2));
    rep(i, 0, sz(ma2) - 1) {
        if (i % 2 == 0)
            ans1 += ma2[i];
        else
            ans2 += ma2[i];
    }
    ll cur = sz(ma2) % 2;
    if (cur == 1) {
        rep(i, 0, sz(ma) - 1) ans1 += ma[i].second, ans2 += ma[i].first;
    } else {
        rep(i, 0, sz(ma) - 1) ans1 += ma[i].first, ans2 += ma[i].second;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
