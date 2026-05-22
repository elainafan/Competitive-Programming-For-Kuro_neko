#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    if ((x & y) == 0) {
        cout << x << ' ' << y << endl;
        return;
    }
    if (x == 1) {
        cout << 0 << ' ' << y << endl;
        return;
    }
    if (y == 1) {
        cout << x << ' ' << 0 << endl;
        return;
    }
    vector<array<array<int, 3>, 3>> vis(31);  // 0一样大，1比x大，2比x小
    vector<array<array<int, 3>, 3>> ma(31);
    vector<pair<int, int>> tem = {{0, 0}, {1, 0}, {0, 1}};
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int v = 0; v <= 2; v++) {
                vis[i][j][v] = false;
                ma[i][j][v] = INT_MAX;
            }
        }
    }
    vector<array<array<pair<int, int>, 3>, 3>> pa(31);
    auto dfs = [&](this auto&& dfs, int t, int tx, int ty) -> int {
        if (t < 0) return 0;
        if (vis[t][tx][ty]) return ma[t][tx][ty];
        ll res = LLONG_MAX;
        int mask = (1 << t);
        for (auto& [a, b] : tem) {
            int ttx = tx, tty = ty;
            int xt = (x >> t) & 1, yt = (y >> t) & 1;
            ll temp = 0;
            if (tx == 0) {
                if (xt < a) {
                    temp += 1LL * mask;
                    ttx = 2;
                } else if (xt > a) {
                    temp += 1LL * mask;
                    ttx = 1;
                } else
                    ttx = 0;
            } else if (tx == 1)
                temp += 1LL * (xt - a) * mask;
            else if (tx == 2)
                temp += 1LL * (a - xt) * mask;
            if (ty == 0) {
                if (yt < b) {
                    temp += 1LL * mask;
                    tty = 2;
                } else if (yt > b) {
                    temp += 1LL * mask;
                    tty = 1;
                } else
                    tty = 0;
            } else if (ty == 1)
                temp += 1LL * (yt - b) * mask;
            else if (ty == 2)
                temp += 1LL * (b - yt) * mask;
            temp += dfs(t - 1, ttx, tty);
            if (temp < res) {
                res = temp;
                pa[t][tx][ty] = {a, b};
            }
        }
        vis[t][tx][ty] = true;
        ma[t][tx][ty] = res;
        return res;
    };
    dfs(30, 0, 0);
    int fx = 0, fy = 0;
    int tx = 0, ty = 0;
    for (int i = 30; i >= 0; i--) {
        auto& [a, b] = pa[i][tx][ty];
        if (a) fx += (1 << i);
        if (b) fy += (1 << i);
        int xt = (x >> i) & 1, yt = (y >> i) & 1;
        if (tx == 0) {
            if (a > xt)
                tx = 2;
            else if (a < xt)
                tx = 1;
        }
        if (ty == 0) {
            if (b > yt)
                ty = 2;
            else if (b < yt)
                ty = 1;
        }
    }
    cout << fx << ' ' << fy << endl;
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
