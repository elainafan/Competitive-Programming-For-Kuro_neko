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
    ll l, r;
    cin >> l >> r;
    ll n = r - l + 1;
    vl a(n);
    ll ans = 0;
    auto dfs = [&](this auto&& dfs, ll tl, ll tr) -> void {
        if (tl > tr) return;
        if (tl == tr) {
            a[tl - l] = tl;
            return;
        }
        ll tem = tl ^ tr;
        int k = 63 - __builtin_clzll((ull)tem);
        ll tem2 = (1LL << k);
        ll tem3 = (tl >> (k + 1)) << (k + 1);
        ll tem4 = tem3 + tem2 - 1;
        ll tem5 = tem3 + (tem2 << 1) - 1;
        ll cnt1 = tem4 - tl + 1;
        ll cnt2 = tr - tem4;
        if (cnt1 <= cnt2) {
            for (ll i = tl; i <= tem4; i++) {
                ll te = tem3 + tem5 - i;
                a[i - l] = te;
                a[te - l] = i;
            }
            dfs(tem3 + tem5 - tl + 1, tr);
        } else {
            for (ll i = tem4 + 1; i <= tr; i++) {
                ll te = tem3 + tem5 - i;
                a[te - l] = i;
                a[i - l] = te;
            }
            dfs(tl, tem3 + tem5 - tr - 1);
        }
    };
    dfs(l, r);
    rep(i, 0, n - 1) { ans += 1LL * ((l + 1LL * i) | a[i]); }
    cout << ans << endl;
    rep(i, 0, n - 1) cout << a[i] << ' ';
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
