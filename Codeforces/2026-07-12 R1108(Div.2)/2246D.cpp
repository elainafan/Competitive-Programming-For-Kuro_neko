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
    ll ans = LLONG_MAX;
    rep(i, 0, 29) {
        ll tem = (1LL << i);
        vl b(n);
        ll tem2 = 0;
        rep(j, 0, n - 1) {
            ll mixx = LLONG_MAX;
            ll idx = -1;
            rep(v, i, 29) {
                ll te = (1LL << v);
                ll te2 = (a[j] % te != 0 ? (a[j] / te + 1) * te : a[j]);
                ll tot = te2 - a[j] + 1LL * popcount((unsigned)te2) + 1LL * log2(te2);
                if (tot < mixx) {
                    mixx = tot, idx = te2;
                }
            }
            b[j] = idx;
            tem2 += idx - a[j];
        }
        ll tem3 = LLONG_MAX;
        rep(j, 0, n - 1) {
            ll te = __builtin_ctz(b[j]);
            tem3 = min(tem3, te);
        }
        tem2 += tem3;
        rep(j, 0, n - 1) {
            b[j] /= (1LL << tem3);
            tem2 += 1LL * popcount((unsigned)b[j]) + 1LL * log2(b[j]);
        }
        ans = min(ans, tem2);
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
