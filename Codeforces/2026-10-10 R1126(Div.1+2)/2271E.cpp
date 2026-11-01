#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll l = n, r = 3 * n, ans, mid;
    auto check = [&](ll mid) -> bool {
        priority_queue<ll, vl, less<>> q;
        rep(i, 0, n - 1) q.emplace(a[i]);
        ll cur = k + n + 2 * ((mid - n) / 2) - 1;
        ll tot = 0;
        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            if (node <= cur)
                cur--;
            else {
                if (tot == (mid - n) / 2) return false;
                tot++;
                q.emplace((node + 1) / 2), q.emplace((node + 1) / 2);
            }
        }
        return true;
    };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
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
