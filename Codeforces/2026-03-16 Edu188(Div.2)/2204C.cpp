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
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    ll a, b, c;
    ll m;
    cin >> a >> b >> c >> m;
    auto check = [&](ll x, ll y) {
        ll g = __gcd(x, y);
        if (x / g > (m + 1) / y) return m + 1;
        return (x / g) * y;
    };
    ll tem = check(a, b);
    ll tot = check(tem, c);
    ll re = m / tot;
    ll tem2 = check(a, c);
    ll tem3 = check(b, c);
    ll re1 = m / tem - re;
    ll re2 = m / tem2 - re;
    ll re3 = m / tem3 - re;
    ll res1 = m / a - (re1 + re2) - re;
    ll res2 = m / b - (re1 + re3) - re;
    ll res3 = m / c - (re2 + re3) - re;
    ll resa = 1LL * 6 * res1 + 1LL * 3 * (re1 + re2) + 1LL * 2 * re;
    ll resb = 1LL * 6 * res2 + 1LL * 3 * (re1 + re3) + 1LL * 2 * re;
    ll resc = 1LL * 6 * res3 + 1LL * 3 * (re2 + re3) + 1LL * 2 * re;
    cout << resa << ' ' << resb << ' ' << resc << endl;
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
