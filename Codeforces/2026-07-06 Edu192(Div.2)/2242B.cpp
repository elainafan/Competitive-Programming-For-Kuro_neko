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
    vl pre1(n), pre2(n);
    pre1[0] = (a[0] == 1 ? 1 : -1);
    rep(i, 1, n - 1) pre1[i] = pre1[i - 1] + (a[i] == 1 ? 1 : -1);
    pre2[0] = ((a[0] == 1 || a[0] == 2) ? 1 : -1);
    rep(i, 1, n - 1) pre2[i] = pre2[i - 1] + ((a[i] == 1 || a[i] == 2) ? 1 : -1);
    ll mixx = LLONG_MAX;
    rep(i, 0, n - 2) {
        if (mixx <= pre2[i]) {
            cout << "YES" << endl;
            return;
        }
        if (pre1[i] >= 0) mixx = min(mixx, pre2[i]);
    }
    cout << "NO" << endl;
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
