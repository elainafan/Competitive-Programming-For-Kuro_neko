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
    ll n, q, x, y;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pre(n);
    pre[0] = a[0];
    rep(i, 1, n - 1) pre[i] = pre[i - 1] + a[i];
    vl pre2(n);
    pre2[0] = 0;
    rep(i, 1, n - 1) pre2[i] = pre2[i - 1] + (a[i] == a[i - 1]);
    rep(i, 0, q - 1) {
        cin >> x >> y;
        x--, y--;
        ll tem = (x == 0 ? 0 : pre[x - 1]);
        ll tem2 = pre[y] - tem;
        if (tem2 % 3 != 0 || (y - x + 1 - tem2) % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        ll tem3 = pre2[x];
        ll tem4 = pre2[y] - tem3;
        cout << ((y - x + 1) / 3) + (tem4 == 0) << endl;
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
