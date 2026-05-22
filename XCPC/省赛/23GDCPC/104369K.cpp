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
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
void solve() {
    ll n, m, k, x, y;
    cin >> n >> m >> k;
    ll tem = 0;
    auto check = [&](int x, int y) -> int { return x * m + y; };
    rep(i, 0, k - 1) {
        cin >> x >> y;
        x--, y--;
        tem |= (1LL << check(x, y));
    }
    map<ll, int> ma;
    auto dfs = [&](this auto&& dfs, ll tem2) -> int {
        if (ma.count(tem2)) return ma[tem2];
        ll res = popcount((ull)tem2);
        rep(i, 0, n - 1) {
            rep(j, 0, m - 1) {
                int tem = check(i, j);
                if (((tem2 >> tem) & 1) == 0) continue;
                rep(v, 1, 4) {
                    int ax = i + dx[v], ay = j + dy[v];
                    int bx = i + 2 * dx[v], by = j + 2 * dy[v];
                    if (ax < 0 || ax >= n || ay < 0 || ay >= m) continue;
                    if (bx < 0 || bx >= n || by < 0 || by >= m) continue;
                    int tem3 = check(ax, ay);
                    int tem4 = check(bx, by);
                    if (((tem2 >> tem3) & 1) == 1 && ((tem2 >> tem4) & 1) == 0) {
                        res = min(res, 1LL * dfs(tem2 ^ (1LL << tem) ^ (1LL << tem3) ^ (1LL << tem4)));
                    }
                }
            }
        }
        ma[tem2] = res;
        return res;
    };
    cout << dfs(tem) << endl;
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
