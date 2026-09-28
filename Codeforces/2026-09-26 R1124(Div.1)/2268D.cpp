#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
struct Node {
    int a[3];
    ll b;
};
void solve() {
    ll n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i], a[i]--;
    ll ans = (n - 1) * n / 2;
    stack<int> s;
    vi r(n, n);
    frep(i, n - 1, 0) {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (!s.empty()) r[i] = s.top();
        s.push(i);
    }
    vvi ma(n);
    rep(i, 0, n - 1) {
        if (r[i] != n) ma[r[i]].push_back(i);
    }
    vi siz(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        siz[x] = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            siz[x] += siz[p];
        }
        return;
    };
    rep(i, 0, n - 1) {
        if (r[i] == n) dfs(i, -1);
    }
    auto dfs2 = [&](this auto&& dfs2, int x, bool flag) -> Node {
        Node res = {{1, 0, 0}, 0};
        if (ma[x].empty()) return res;
        ll idx = ma[x][0];
        ll re = siz[x] - siz[idx] - 1;
        auto tem = dfs2(idx, flag);
        Node cur = {0, tem.a[0], tem.a[1], tem.b + siz[idx] - tem.a[0] - tem.a[1] - tem.a[2] + 3 * tem.a[2]};
        ans += (flag ? cur.a[1] + 2 * cur.a[2] + cur.b : cur.a[1] + 2 * cur.a[2] + 3 * (siz[idx] - cur.a[0] - cur.a[1] - cur.a[2]));
        Node cur2 = {0, cur.a[0], cur.a[1], cur.b + siz[idx] - cur.a[0] - cur.a[1] - cur.a[2] + 3 * cur.a[2]};
        ans += (flag ? cur2.a[1] + 2 * cur2.a[2] + cur2.b : cur2.a[1] + 2 * cur2.a[2] + 3 * (siz[idx] - cur2.a[0] - cur2.a[1] - cur2.a[2])) * re;
        rep(i, 0, 2) res.a[i] += cur.a[i];
        res.b += cur.b;
        for (auto& p : ma[x]) {
            if (p == idx) continue;
            dfs2(p, false);
            re -= siz[p];
            ans += 1 + 2 * (siz[p] - 1);
            ans += (2 + 3 * (siz[p] - 1)) * re;
            res.a[1]++, res.a[2] += siz[p] - 1;
        }
        return res;
    };
    rep(i, 0, n - 1) {
        if (r[i] == n) dfs2(i, true);
    }
    cout << ans << endl;
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
