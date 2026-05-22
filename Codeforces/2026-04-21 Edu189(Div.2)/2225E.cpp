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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
#define endl '\n'
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    ll n, r;
    cin >> n >> r;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    ll bias = 1e5;
    ll tem = 0;
    while (tem * tem < 3 * r * r) tem++;
    while (true) {
        ll dx = rng() % (2 * r);
        ll dy = rng() % tem;
        int cnt = 0;
        set<pii> res;
        for (auto& [x, y] : ma) {
            ll tx = x + bias;
            ll ty = y + bias;
            ll cntx = tx / (2 * r);
            ll cnty = ty / tem;
            bool flag = false;
            rep(i, cntx - 2, cntx + 2) {
                if (flag) break;
                rep(j, cnty - 2, cnty + 2) {
                    ll tx2 = i * 2 * r + (j % 2 == 0 ? r : 0) + dx;
                    ll ty2 = j * tem + dy;
                    ll dis = (tx2 - tx) * (tx2 - tx) + (ty2 - ty) * (ty2 - ty);
                    if (dis <= r * r) {
                        flag = true;
                        res.insert({tx2 - bias, ty2 - bias});
                    }
                }
            }
            if (flag) cnt++;
        }
        if (cnt * 100 >= 89 * n) {
            cout << sz(res) << endl;
            for (auto& [x, y] : res) cout << x << ' ' << y << endl;
            return;
        }
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
