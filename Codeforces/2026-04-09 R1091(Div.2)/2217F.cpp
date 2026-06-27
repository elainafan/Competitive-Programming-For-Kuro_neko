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
    ll x1, x2;
    cin >> x1 >> x2;
    const ll MX = 21;
    auto calc = [&](ll x, ll y) -> ll {
        vl pre(MX);
        pre[0] = ((y & 1) == 0);
        rep(i, 1, MX - 1) pre[i] = pre[i - 1] + (((y >> i) & 1) == 0);
        ll res = 0;
        frep(i, MX - 1, 0) {
            if (x >> i & 1) {
                res += (i == 0 ? 1 : (1LL << pre[i - 1]));
                if (y >> i & 1) return res;
            }
        }
        return res + 1;
    };
    ll ans = 0;
    ll mixx = LLONG_MAX;
    rep(i, 0, x1 - 1) {
        if (x2 < 1 + i) {
            mixx = 0;
            ans = i;
            break;
        }
        ll cnt = calc((x2 - 1 - i) / 2, i) * (1LL << popcount((unsigned)i));
        if (cnt < mixx) {
            mixx = cnt;
            ans = i;
        }
    }
    cout << ans + 1 << ' ' << x1 << endl;
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
