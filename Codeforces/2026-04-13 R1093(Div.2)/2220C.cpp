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
    ll p, q;
    cin >> p >> q;
    ll tem = 2 * p + 4 * q + 1;
    for (ll i = 3; i * i <= tem; i += 2) {
        if (tem % i != 0) continue;
        ll tem2 = tem / i;
        ll n = (i - 1) / 2, m = (tem2 - 1) / 2;
        if (q > min(n * (m + 1), m * (n + 1))) {
            continue;
        }
        cout << n << ' ' << m << endl;
        return;
    }
    cout << -1 << endl;
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
