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
    cin >> a >> b >> c;
    ll ans = 0;
    ll tem = min(a, c);
    a -= tem, c -= tem, ans += 4 * tem;
    if (a > 0 && b > 0) {
        if (a <= 2 * b)
            ans += 3 * b + 2 * a;
        else
            ans += 3 * b + 2 * a + 1;
    } else if (a > 0) {
        ans += 2 * a + 1;
    } else if (b > 0) {
        ans += 3 * b;
    }
    if (c > 0) ans += 3 * c;
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
