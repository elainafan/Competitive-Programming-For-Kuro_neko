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
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    vi tem(n);
    auto lcm = [&](ll x, ll y) -> ll {
        ll tem = __gcd(x, y);
        return x / tem * y;
    };
    rep(i, 0, n - 1) {
        if (i == 0) {
            tem[i] = __gcd(a[i], a[i + 1]);
        } else if (i == n - 1) {
            tem[i] = __gcd(a[i], a[i - 1]);
        } else {
            tem[i] = lcm(__gcd(a[i], a[i + 1]), __gcd(a[i], a[i - 1]));
        }
    }
    int ans = 0;
    rep(i, 0, n - 1) {
        if (a[i] != tem[i]) ans++;
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
