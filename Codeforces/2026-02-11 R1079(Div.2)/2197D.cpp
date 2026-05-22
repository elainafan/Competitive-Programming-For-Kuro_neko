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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 0;
    int B = sqrt(n);
    rep(i, 1, B - 1) {
        rep(j, 0, n - 1) {
            ll tem = 1LL * j + 1LL * i * a[j];
            if (tem < 0 || tem >= n) continue;
            if (a[tem] == i) ans++;
        }
    }
    rep(i, 0, n - 1) {
        ll tem = a[i];
        if (a[i] < B) continue;
        while (tem <= i) {
            ll tem2 = 1LL * i - tem;
            if (tem2 < 0) break;
            if (a[tem2] == tem / (1LL * a[i])) ans++;
            tem += 1LL * a[i];
        }
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
