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
    ll n, q, x;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pre(n);
    pre[0] = a[0];
    rep(i, 1, n - 1) pre[i] = pre[i - 1] ^ a[i];
    vvl cnt(n + 1, vl(31, -1));
    rep(i, 0, n - 1) {
        rep(j, 0, 30) cnt[i + 1][j] = cnt[i][j];
        int tem = 63 - __builtin_clzll(a[i]);
        rep(j, 0, tem) { cnt[i + 1][j] = i; }
    }
    rep(i, 0, q - 1) {
        cin >> x;
        ll ans = 0;
        ll cur = n;
        while (cur > 0 && x > 0) {
            int tem = 63 - __builtin_clzll(x);
            ll tem2 = cnt[cur][tem];
            x = x ^ pre[cur - 1];
            x = x ^ (tem2 < 0 ? 0 : pre[tem2]);
            ans += cur - tem2 - 1;
            cur = tem2;
            if (cur < 0 || a[cur] > x) break;
            x = x ^ a[cur];
            ans++;
        }
        cout << ans << ' ';
    }
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
