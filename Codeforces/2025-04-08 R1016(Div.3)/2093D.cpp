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
    ll n, q, x, y;
    string op;
    cin >> n >> q;
    auto dfs = [&](this auto&& dfs, ll qx, ll qy, ll x, ll y, ll len) -> ll {
        if (len == 2) {
            if (qx == x && qy == y) return 1;
            if (qx == x + 1 && qy == y + 1) return 2;
            if (qx == x + 1 && qy == y) return 3;
            if (qx == x && qy == y + 1) return 4;
        }
        ll tem = (len / 2) * (len / 2);
        if (qx < x + len / 2 && qy < y + len / 2) return dfs(qx, qy, x, y, len / 2);
        if (qx >= x + len / 2 && qy >= y + len / 2) return tem + dfs(qx, qy, x + len / 2, y + len / 2, len / 2);
        if (qx >= x + len / 2 && qy < y + len / 2) return 2 * tem + dfs(qx, qy, x + len / 2, y, len / 2);
        if (qx < x + len / 2 && qy >= y + len / 2) return 3 * tem + dfs(qx, qy, x, y + len / 2, len / 2);
    };
    auto dfs2 = [&](this auto&& dfs2, ll d, ll x, ll y, ll len) -> pll {
        if (len == 2) {
            if (d == 1) return {x, y};
            if (d == 2) return {x + 1, y + 1};
            if (d == 3) return {x + 1, y};
            if (d == 4) return {x, y + 1};
        }
        ll tem = (len / 2) * (len / 2);
        if (d <= tem) return dfs2(d, x, y, len / 2);
        if (d <= 2 * tem) return dfs2(d - tem, x + len / 2, y + len / 2, len / 2);
        if (d <= 3 * tem) return dfs2(d - 2 * tem, x + len / 2, y, len / 2);
        if (d <= 4 * tem) return dfs2(d - 3 * tem, x, y + len / 2, len / 2);
    };
    rep(i, 0, q - 1) {
        cin >> op;
        if (op == "->") {
            cin >> x >> y;
            cout << dfs(x, y, 1, 1, (1LL << n)) << endl;
        } else {
            cin >> x;
            auto [a, b] = dfs2(x, 1, 1, (1LL << n));
            cout << a << ' ' << b << endl;
        }
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
