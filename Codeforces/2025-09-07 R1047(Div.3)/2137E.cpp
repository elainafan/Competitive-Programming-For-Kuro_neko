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
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int cnt = 0;
    map<ll, ll> ma;
    rep(i, 0, n - 1) ma[a[i]]++;
    while (ma.count(cnt)) cnt++;
    vl b(n);
    rep(i, 0, n - 1) {
        if (a[i] < cnt && ma[a[i]] == 1)
            b[i] = a[i];
        else
            b[i] = cnt;
    }
    ll ans = 0;
    if (k == 1) {
        rep(i, 0, n - 1) ans += b[i];
        cout << ans << endl;
        return;
    }
    ma.clear();
    vl c(n);
    int cnt2 = 0;
    rep(i, 0, n - 1) ma[b[i]]++;
    while (ma.count(cnt2)) cnt2++;
    rep(i, 0, n - 1) {
        if (b[i] < cnt2 && ma[b[i]] == 1)
            c[i] = b[i];
        else
            c[i] = cnt2;
    }
    vl d(n);
    int cnt3 = 0;
    ma.clear();
    rep(i, 0, n - 1) ma[c[i]]++;
    while (ma.count(cnt3)) cnt3++;
    rep(i, 0, n - 1) {
        if (c[i] < cnt3 && ma[c[i]] == 1)
            d[i] = c[i];
        else
            d[i] = cnt3;
    }
    rep(i, 0, n - 1) ans += (k % 2 == 0 ? c[i] : d[i]);
    cout << ans << endl;
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
