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
    ll ans = 0;
    vvl ma(n + 1, vl(n + 1, INT_MAX / 3));
    rep(i, 0, n - 1) {
        vl s(n + 1);
        ll maxx = LLONG_MIN / 3, mixx = LLONG_MAX / 3;
        rep(j, i, n - 1) {
            if (j - i + 1 > n / 2 || s[a[j]]) break;
            maxx = max(maxx, a[j]), mixx = min(mixx, a[j]);
            s[a[j]] = 1;
            if (j - i + 1 <= ans) continue;
            if (maxx - mixx + 1 == j - i + 1) {
                if (mixx - (j - i + 1) >= 1 && ma[mixx - (j - i + 1)][j - i + 1] != INT_MAX / 3 && ma[mixx - (j - i + 1)][j - i + 1] < i)
                    ans = max(ans, 1LL * (j - i + 1));
                if (mixx + 2 * (j - i + 1) - 1 <= n && ma[mixx + (j - i + 1)][j - i + 1] != INT_MAX / 3 &&
                    ma[mixx + (j - i + 1)][j - i + 1] < i)
                    ans = max(ans, 1LL * (j - i + 1));
                ma[mixx][j - i + 1] = min(ma[mixx][j - i + 1], 1LL * j);
            }
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