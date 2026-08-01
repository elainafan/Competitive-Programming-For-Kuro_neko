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
constexpr ll dx[4] = {0, 0, 1, -1};
constexpr ll dy[4] = {1, -1, 0, 0};
void solve() {
    ll n;
    cin >> n;
    vvl ma(n, vl(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) cin >> ma[i][j]; }
    vvl res(n, vl(n));
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            if (ma[i][j] == 1)
                res[i][j] = 2;
            else if (ma[i][j] == 2)
                res[i][j] = 4;
            else if (ma[i][j] == 3)
                res[i][j] = 1;
            else
                res[i][j] = 3;
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) cout << res[i][j] << ' ';
        cout << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
