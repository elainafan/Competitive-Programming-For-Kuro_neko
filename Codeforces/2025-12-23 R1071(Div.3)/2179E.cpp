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
void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 0;
    rep(i, 0, n - 1) ans += a[i];
    if (ans > x + y) {
        cout << "NO" << endl;
        return;
    }
    vl b(n), c(n);
    rep(i, 0, n - 1) {
        if (s[i] == '0') {
            b[i] = a[i] / 2 + 1;
        } else {
            c[i] = a[i] / 2 + 1;
        }
    }
    ll tem1 = 0, tem2 = 0;
    rep(i, 0, n - 1) { tem1 += b[i], tem2 += c[i]; }
    if (tem1 != 0 && tem2 != 0) {
        if (tem1 > x || tem2 > y)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    } else if (tem1 == 0) {
        if (tem2 <= y && y >= x + n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else if (tem2 == 0) {
        if (tem1 <= x && x >= y + n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
