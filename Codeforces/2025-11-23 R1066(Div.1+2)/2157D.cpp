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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::sort(a);
    vl pre(n);
    vl suf(n + 1);
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    rep(i, 1, n - 1) pre[i] = pre[i - 1] + a[i];
    frep(i, n - 2, 0) suf[i] = suf[i + 1] + a[i];
    ll ans = 0;
    // 枚举选择a[i]-p的数量
    // 假设a[i]-p的数量为y，p-a[i]的数量为x
    // 当y>=x时，p应该取l
    // 当y<x时，p应该取r
    rep(i, 0, n - 1) {
        if (a[i] < l) ans += l - a[i], a[i] = l;
        if (a[i] > r) ans += a[i] - r, a[i] = r;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        ans += a[j] - a[i];
    }
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
