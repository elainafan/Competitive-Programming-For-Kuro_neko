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
    map<ll, ll> ma;
    rep(i, 0, n - 1) ma[a[i]]++;
    for (auto& [x, y] : ma) {
        if (y % k != 0) {
            cout << 0 << endl;
            return;
        }
    }
    ll l = 0;
    ll ans = 0;
    map<ll, ll> ma2;
    rep(r, 0, n - 1) {
        ma2[a[r]]++;
        while (ma2[a[r]] > ma[a[r]] / k) {
            ma2[a[l]]--;
            l++;
        }
        ans += 1LL * r - l + 1;
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
