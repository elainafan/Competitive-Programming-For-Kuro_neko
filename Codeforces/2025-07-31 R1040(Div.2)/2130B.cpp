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
    ll n, s;
    cin >> n >> s;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll tot0 = 0, tot1 = 0, tot2 = 0;
    rep(i, 0, n - 1) {
        if (a[i] == 0)
            tot0++;
        else if (a[i] == 1)
            tot1++;
        else
            tot2++;
    }
    ll tot = tot1 + tot2 * 2;
    if (tot > s) {
        rep(i, 0, n - 1) cout << a[i] << ' ';
        cout << endl;
        return;
    }
    if (tot == s) {
        cout << -1 << endl;
        return;
    }
    for (ll i = 0; i <= s - tot; i += 2) {
        if ((s - tot - i) % 3 == 0) {
            cout << -1 << endl;
            return;
        }
    }
    rep(i, 0, tot0 - 1) cout << 0 << ' ';
    rep(i, 0, tot2 - 1) cout << 2 << ' ';
    rep(i, 0, tot1 - 1) cout << 1 << ' ';
    cout << endl;
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
