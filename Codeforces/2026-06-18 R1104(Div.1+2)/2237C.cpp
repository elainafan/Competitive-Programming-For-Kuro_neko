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
    ll l = 1, r = 1e18, mid, ans = 1;
    auto check = [&](ll mid) -> bool {
        if (a[0] > mid) return false;
        ll tem = a[0];
        rep(i, 1, n - 1) {
            if (tem > a[i])
                tem = a[i] + tem;
            else
                tem = a[i];
            if (tem > mid) return false;
        }
        return true;
    };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
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
