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
using namespace std;
using i128 = __int128_t;
constexpr int MX = 2e5 + 5;
vector<int> divisors[MX];
auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();
void solve() {
    ll n, m, q, x;
    cin >> n >> m >> q;
    vl a(n), b(m);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, m - 1) cin >> b[i];
    ll tot1 = 0;
    ll tot2 = 0;
    rep(i, 0, n - 1) tot1 += a[i];
    rep(i, 0, m - 1) tot2 += b[i];
    set<ll> s1;
    set<ll> s2;
    rep(i, 0, n - 1) s1.insert(tot1 - a[i]);
    rep(i, 0, m - 1) s2.insert(tot2 - b[i]);
    rep(i, 0, q - 1) {
        cin >> x;
        if (x < 0) {
            bool flag = false;
            x = -x;
            for (auto& p : divisors[x]) {
                ll tem1 = p, tem2 = x / p;
                if (s1.count(-tem1) && s2.count(tem2)) {
                    flag = true;
                    break;
                }
                if (s1.count(tem2) && s2.count(-tem1)) {
                    flag = true;
                    break;
                }
            }
            cout << (flag ? "YES" : "NO") << endl;
        } else {
            bool flag = false;
            for (auto& p : divisors[x]) {
                ll tem1 = p, tem2 = x / p;
                if (s1.count(tem1) && s2.count(tem2)) {
                    flag = true;
                    break;
                }
                if (s1.count(-tem1) && s2.count(-tem2)) {
                    flag = true;
                    break;
                }
            }
            cout << (flag ? "YES" : "NO") << endl;
        }
    }
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
