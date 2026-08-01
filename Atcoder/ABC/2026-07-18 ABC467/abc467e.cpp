#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
    ll n, m;
    cin >> n >> m;
    vl a(n), b(n - 1);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 2) cin >> b[i];
    ll tot = 0;
    ll tem = 0;
    vector<pll> tem2;
    rep(i, 0, n - 1) {
        tot += (tem - a[i] + m) % m;
        if (i % 2 == 1 && (tem - a[i] + m) % m != m - 1) {
            tem2.emplace_back((tem - a[i] + m) % m + 1, m);
        } else if (i % 2 == 0 && (tem % m != a[i] % m)) {
            tem2.emplace_back(m - (tem - a[i] + m) % m, -m);
        }
        if (i == n - 1) break;
        tem = (b[i] - tem + m) % m;
    }
    ranges::sort(tem2);
    int m1 = sz(tem2);
    ll ans = tot;
    int i = 0;
    while (i <= m1 - 1) {
        int j = i;
        ll tot2 = 0;
        while (j <= m1 - 1 && tem2[j].first == tem2[i].first) {
            tot2 += tem2[j].second;
            j++;
        }
        tot += 1LL * (n % 2 == 1 ? 1 : 0) * (tem2[i].first - (i == 0 ? 0 : tem2[i - 1].first)) + tot2;
        ans = min(ans, tot);
        i = j;
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
