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
    int n, h, k;
    cin >> n >> h >> k;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll tot = 0;
    rep(i, 0, n - 1) tot += 1LL * a[i];
    int cnt = h / tot, r = h % tot;
    ll res;
    if (r == 0)
        res = 1LL * (cnt - 1) * k + 1LL * n * cnt;
    else
        res = 1LL * cnt * k + 1LL * n * cnt;
    if (r == 0) {
        cout << res << endl;
        return;
    }
    vi suf(n);
    suf[n - 1] = a[n - 1];
    frep(i, n - 2, 0) { suf[i] = max(suf[i + 1], a[i]); }
    ll tem = 0;
    ll mixx = LLONG_MAX;
    rep(i, 0, n - 1) {
        mixx = min(mixx, 1LL * a[i]);
        tem += 1LL * a[i];
        if (tem >= r) {
            cout << res + 1LL * i + 1LL << endl;
            return;
        }
        if (i < n - 1 && tem + 1LL * suf[i + 1] - mixx >= r) {
            cout << res + 1LL * i + 1LL << endl;
            return;
        }
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
