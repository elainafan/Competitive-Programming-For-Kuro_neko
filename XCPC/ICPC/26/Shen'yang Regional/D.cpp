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
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
void solve() {
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    if (a + b > n + 1) {
        cout << -1 << endl;
        return;
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (a == 1 && b == 1) {
        cout << -1 << endl;
        return;
    }
    if (b == 1) {
        if (k == 1)
            cout << 1 << endl;
        else if (k <= a)
            cout << n - a + k << endl;
        else
            cout << (n - a + 1) - (k - a - 1) << endl;
    } else {
        if (k <= a)
            cout << (n - a + k) << endl;
        else if (k <= a + b - 2)
            cout << n - k + 1 << endl;
        else if (k == a + b - 1)
            cout << 1 << endl;
        else
            cout << (n - a - b + 3) - (k - (a + b - 1)) << endl;
    }
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
