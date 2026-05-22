#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define endl '\n'
using namespace std;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};
void solve() {
    int n, m;
    cin >> n >> m;
    vvi ma(n, vi(m));
    rep(i, 0, n - 1) { rep(j, 0, m - 1) cin >> ma[i][j]; }
    vi vis(n * m + 1);
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            if (vis[ma[i][j]] == 0) vis[ma[i][j]] = 1;
            rep(v, 0, 3) {
                int ax = i + dx[v], ay = j + dy[v];
                if (ax >= 0 && ax <= n - 1 && ay >= 0 && ay <= m - 1) {
                    if (ma[ax][ay] == ma[i][j]) vis[ma[i][j]] = 2;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1, m * n) { ans += vis[i]; }
    int ans2 = INT_MAX;
    rep(i, 1, m * n) ans2 = min(ans2, ans - vis[i]);
    cout << ans2 << endl;
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