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
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    ll tot1 = 0, tot2 = 0;
    ll tot3 = 0, tot4 = 0;
    rep(i, 0, n - 1) {
        if (a[i] == 1 && b[i] == 0)
            tot1++;
        else if (a[i] == 0 && b[i] == 1)
            tot2++;
        else if (a[i] == 1 && b[i] == 1)
            tot3++;
        else
            tot4++;
    }
    if (tot1 == 0 && tot2 == 0) {
        cout << 0 << endl;
        return;
    }
    if (tot1 % 2 == 1) {
        cout << 1 << endl;
        return;
    }
    if (tot1 > 0) {
        cout << 2 << endl;
        return;
    }
    if (tot3 > 0 && tot4 > 0) {
        cout << 2 << endl;
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
