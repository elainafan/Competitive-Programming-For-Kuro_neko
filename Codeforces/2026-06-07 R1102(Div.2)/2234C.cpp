#include <bits/stdc++.h>
#define endl '\n'
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
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl res(n);
    rep(i, 0, n - 1) {
        vl tem;
        rep(j, i, i + n - 1) tem.push_back(a[j % n]);
        vl pre(n);
        pre[0] = tem[0];
        rep(j, 1, n - 1) pre[j] = max(pre[j - 1], tem[j]);
        vl suf(n);
        suf[n - 1] = tem[n - 1];
        frep(j, n - 2, 0) suf[j] = max(suf[j + 1], tem[j]);
        ll ans = 0;
        rep(j, 1, n - 1) { ans += min(pre[j - 1], suf[j]); }
        res[i] = ans;
    }
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
