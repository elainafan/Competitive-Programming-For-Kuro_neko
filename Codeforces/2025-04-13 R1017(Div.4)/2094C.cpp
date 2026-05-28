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
    vvl ma(n, vl(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) cin >> ma[i][j]; }
    vl res(2 * n + 1);
    vl cnt(2 * n + 1);
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            res[i + j + 2] = ma[i][j];
            cnt[ma[i][j]]++;
        }
    }
    int idx = -1;
    rep(i, 1, 2 * n) {
        if (cnt[i] == 0) {
            idx = i;
            break;
        }
    }
    rep(i, 1, 2 * n) {
        if (res[i] == 0) {
            res[i] = idx;
            break;
        }
    }
    rep(i, 1, 2 * n) cout << res[i] << ' ';
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
