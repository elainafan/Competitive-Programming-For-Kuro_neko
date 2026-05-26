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
    int n;
    cin >> n;
    vl a(2 * n);
    rep(i, 0, 2 * n - 1) cin >> a[i];
    ranges::sort(a);
    ll tem1 = 0;
    ll tem2 = 0;
    rep(i, 0, n - 2) tem2 += 1LL * a[i];
    rep(i, n - 1, 2 * n - 1) tem1 += 1LL * a[i];
    ll tem = tem1 - tem2;
    vl b(2 * n + 1);
    for (int i = 0; i <= 2 * n; i += 2) b[i] = a[2 * n - 1 - i / 2];
    for (int i = 1; i < 2 * n - 1; i += 2) b[i] = a[(i - 1) / 2];
    b[2 * n - 1] = tem;
    for (ll p : b) cout << p << ' ';
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