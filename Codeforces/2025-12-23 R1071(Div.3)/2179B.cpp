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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 0;
    rep(i, 0, n - 2) ans += abs(a[i + 1] - a[i]);
    ll ans2 = ans;
    rep(i, 1, n - 2) { ans2 = min(ans2, ans + abs(a[i + 1] - a[i - 1]) - abs(a[i + 1] - a[i]) - abs(a[i] - a[i - 1])); }
    ans2 = min(ans2, ans - abs(a[1] - a[0]));
    ans2 = min(ans2, ans - abs(a[n - 1] - a[n - 2]));
    cout << ans2 << endl;
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
