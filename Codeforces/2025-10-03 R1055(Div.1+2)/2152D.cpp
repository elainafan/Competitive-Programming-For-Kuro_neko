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
    vl b(n);
    rep(i, 0, n - 1) {
        if ((a[i] & (a[i] - 1)) == 0)
            b[i] = 1;
        else if (((a[i] - 2) & (a[i] - 1)) == 0)
            b[i] = 2;
        else
            b[i] = 3;
    }
    vl pre(n);
    vl pre2(n);
    vl pre3(n);
    pre[0] = 1LL * log2(a[0]);
    pre2[0] = (b[0] == 2);
    pre3[0] = (b[0] == 3);
    rep(i, 1, n - 1) {
        pre[i] = pre[i - 1] + 1LL * log2(a[i]);
        pre2[i] = pre2[i - 1] + (b[i] == 2);
        pre3[i] = pre3[i - 1] + (b[i] == 3);
    }
    rep(i, 0, q - 1) {
        cin >> x >> y;
        x--, y--;
        ll tem = (x == 0 ? 0 : pre[x - 1]);
        ll tem2 = (x == 0 ? 0 : pre2[x - 1]);
        ll tem3 = (x == 0 ? 0 : pre3[x - 1]);
        cout << pre[y] - tem + (pre2[y] - tem2) / 2 + (pre3[y] - tem3) << endl;
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
