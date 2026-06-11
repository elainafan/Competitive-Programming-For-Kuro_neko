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
    rep(i, 0, n - 1) {
        if (i % 2 == 0)
            ans += a[i];
        else
            ans -= a[i];
    }
    ll ans2 = ans;
    ans2 = max(ans2, ans + (n % 2 == 0 ? n - 2 : n - 1));
    set<ll> tem;
    rep(i, 0, n - 1) {
        if (i % 2 == 1)
            tem.insert(2 * a[i] - i);
        else {
            if (!tem.empty()) ans2 = max(ans2, ans + *prev(tem.end()) - (2 * a[i] - i));
        }
    }
    tem.clear();
    rep(i, 0, n - 1) {
        if (i % 2 == 1) {
            if (!tem.empty()) ans2 = max(ans2, ans + 2 * a[i] + i - *tem.begin());
        } else {
            tem.insert(2 * a[i] + i);
        }
    }
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
