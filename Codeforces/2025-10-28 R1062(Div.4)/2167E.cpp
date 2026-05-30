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
    ll n, k, x;
    cin >> n >> k >> x;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::sort(a);
    ll l = 0, r = 1e9, mid, ans = 0;
    auto check = [&](ll mid) -> bool {
        ll res = 0;
        rep(i, 0, n - 1) {
            if (i == 0) {
                res += max(0LL, a[i] - mid + 1);
            }
            if (i != n - 1) {
                res += max(0LL, a[i + 1] - a[i] - 2 * mid + 1);
            } else {
                res += max(0LL, x - a[i] - mid + 1);
            }
        }
        return res >= k;
    };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    if (ans == 0) {
        rep(i, 0, k - 1) cout << i << ' ';
        return;
    }
    vl res(k);
    int idx = 0;
    rep(i, 0, n - 1) {
        if (i == 0) {
            for (int j = 0; j <= a[i] - ans && idx < k; j++) res[idx++] = j;
        }
        if (i == n - 1) {
            for (int j = a[i] + ans; j <= x && idx < k; j++) res[idx++] = j;
        } else {
            for (int j = a[i] + ans; j <= a[i + 1] - ans && idx < k; j++) res[idx++] = j;
        }
    }
    rep(i, 0, k - 1) cout << res[i] << ' ';
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
