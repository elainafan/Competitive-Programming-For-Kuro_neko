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
constexpr int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> ma(n);
    rep(i, 0, n - 1) cin >> ma[i];
    vvi dis(n, vi(m, -1));
    queue<pii> q;
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            bool flag = false;
            rep(v, 0, 7) {
                int ax = i + dx[v], ay = j + dy[v];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || ma[ax][ay] == ma[i][j]) continue;
                flag = true;
            }
            if (flag) {
                dis[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    if (q.empty()) {
        rep(i, 0, n - 1) {
            rep(j, 0, m - 1) cout << '.';
            cout << endl;
        }
        return;
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        rep(i, 0, 7) {
            int ax = x + dx[i], ay = y + dy[i];
            if (ax < 0 || ax >= n || ay < 0 || ay >= m || dis[ax][ay] != -1 || ma[ax][ay] != ma[x][y]) continue;
            dis[ax][ay] = dis[x][y] + 1;
            q.emplace(ax, ay);
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            if (ma[i][j] == '#') {
                if (dis[i][j] & 1)
                    cout << '.';
                else
                    cout << '#';
            } else {
                if (dis[i][j] & 1)
                    cout << '#';
                else
                    cout << '.';
            }
        }
        cout << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
