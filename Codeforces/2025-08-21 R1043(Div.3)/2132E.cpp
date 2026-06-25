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
    ll n, m, q, x, y, z;
    cin >> n >> m >> q;
    vl a(n), b(m);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, m - 1) cin >> b[i];
    sort(all2(a)), sort(all2(b));
    vl pre(n + 1), pre2(m + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i - 1];
    rep(i, 1, m) pre2[i] = pre2[i - 1] + b[i - 1];
    rep(i, 0, q - 1) {
        cin >> x >> y >> z;
        ll l = max(0LL, z - y);
        ll r = min(x, z) - 1;
        ll mid, ans = l - 1;
        auto check = [&](ll mid) -> bool { return pre[mid] + pre2[z - mid] <= pre[mid + 1] + pre2[z - mid - 1]; };
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        cout << pre[ans + 1] + pre2[z - ans - 1] << endl;
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
