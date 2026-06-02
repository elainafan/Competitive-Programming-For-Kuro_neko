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
    ll n;
    cin >> n;
    vl res(1 << n);
    vi vis(1 << n);
    int idx = 1;
    res[0] = (1 << n) - 1;
    vis[(1 << n) - 1] = 1;
    frep(i, n - 1, 0) {
        rep(j, 0, (1 << (n - i)) - 1) {
            if (vis[(j << i) | ((1 << i) - 1)]) continue;
            vis[(j << i) | ((1 << i) - 1)] = 1;
            res[idx++] = ((j << i) | ((1 << i) - 1));
        }
    }
    rep(i, 0, (1 << n) - 1) {
        if (!vis[i]) res[idx++] = i;
    }
    rep(i, 0, (1 << n) - 1) cout << res[i] << ' ';
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
