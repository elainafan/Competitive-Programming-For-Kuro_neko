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
    ll n, c;
    cin >> n >> c;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    ll ans = 0;
    vl vis(n, -1);
    rep(i, 0, n - 1) {
        ll tem = LLONG_MAX;
        int idx = -1;
        rep(j, 0, n - 1) {
            if (a[j] < b[i] || vis[j] != -1) continue;
            if (tem > a[j] - b[i]) {
                idx = j;
                tem = a[j] - b[i];
            }
        }
        if (idx == -1) {
            cout << -1 << endl;
            return;
        }
        ans += tem;
        vis[idx] = i;
    }
    ans += c;
    ll ans2 = 0;
    rep(i, 0, n - 1) {
        if (a[i] < b[i]) {
            ans2 = LLONG_MAX;
            break;
        }
        ans2 += a[i] - b[i];
    }
    cout << min(ans, ans2) << endl;
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
