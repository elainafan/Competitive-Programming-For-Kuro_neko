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
    auto calc = [&](ll x) -> ll {
        ll ans = 0;
        for (ll i = 1; i <= x; i *= 10) {
            ll tem = x / (i * 10);
            ll tem2 = (x / i) % 10;
            ll tem3 = x % i;
            ans += tem * i * 45 + tem2 * (tem2 - 1) / 2 * i + tem2 * (tem3 + 1);
        }
        return ans;
    };
    auto calc2 = [&](ll x) -> ll {
        ll ans = 0;
        ll l = 1;
        for (ll i = 1; l <= x; i++) {
            ll tem = min(x, l * 10 - 1);
            ans += (tem - l + 1) * i;
            l *= 10;
        }
        return ans;
    };

    ll l = 1, r = 1e18, mid, ans;
    auto check = [&](ll mid) { return calc2(mid) <= n; };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    ll res = calc(ans);
    ll re = n - calc2(ans);
    string s = to_string(ans + 1);
    rep(i, 0, re - 1) res += (s[i] - '0');
    cout << res << endl;
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
