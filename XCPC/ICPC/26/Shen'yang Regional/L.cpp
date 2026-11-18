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
    string s;
    cin >> s;
    ll n = sz(s);
    string res;
    rep(i, 0, n - 1) {
        if (s[i] == '-') {
            if (res.empty()) continue;
            res.pop_back();
        } else {
            if (sz(res) >= 1 && s[i] == res[sz(res) - 1]) continue;
            if (sz(res) >= 2 && s[i] == res[sz(res) - 2]) continue;
            res.push_back(s[i]);
        }
    }
    if (res.empty())
        cout << '-' << endl;
    else
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
