#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
using namespace std;
const ll MOD = 1e9 + 7;
const ll inv2 = 500000004;
const ll inv6 = 166666668;
void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ans += max(k - n, 0LL) % MOD * n % MOD;
    int B = (int)sqrt(n);
    rep(i, 2, min(k, n)) {
        if (i <= B) {
            ll res = 0;
            ll tem = n;
            while (tem) {
                res = (res * i % MOD + tem % i) % MOD;
                tem /= i;
            }
            ans = (ans + res) % MOD;
        } else {
            auto check = [&]() -> void {
                for (ll l = i, r; l <= min(k, n); l = r + 1) {
                    ll v = n / l;
                    r = min(min(n, k), n / v);
                    ll cnt = (r - l + 1) % MOD;
                    ans += n % MOD * (l + r) % MOD * cnt % MOD * inv2 % MOD;
                    ans = (ans + MOD) % MOD;
                    ll tem = r * (r + 1) % MOD * (2 * r + 1) % MOD * inv6 % MOD;
                    ll tem2 = (l - 1) * l % MOD * (2 * l - 1) % MOD * inv6 % MOD;
                    ans -= v * (tem - tem2 + MOD) % MOD;
                    ans = (ans + MOD) % MOD;
                    ans += v * cnt % MOD;
                    ans %= MOD;
                }
            };
            check();
            break;
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