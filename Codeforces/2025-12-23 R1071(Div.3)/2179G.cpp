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
ll ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(vvl& res) {
    cout << "! ";
    ll n = sz(res);
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) cout << res[i][j] << ' ';
        cout << '\n';
    }
    cout.flush();
    return;
}
void solve() {
    ll n;
    cin >> n;
    vvl ma(2 * n + 1);
    vvl ma2(2 * n + 1);
    ll maxx = LLONG_MIN;
    rep(i, 2, n * n) {
        ll op = ask(1, i);
        maxx = max(maxx, op);
        ma[op].push_back(i);
    }
    ll l1 = ma[maxx][0];
    vl dis(n * n + 1);
    rep(i, 1, n * n) {
        if (i == l1) continue;
        ll op = ask(i, l1);
        ma2[op].push_back(i);
        dis[i] = op;
    }
    ll l2 = ma2[2 * n - 2][0];
    ll tem = ma2[n - 1][0];
    ll maxx2 = LLONG_MIN;
    ll l3 = -1;
    for (auto& p : ma2[n - 1]) {
        ll op = ask(tem, p);
        if (op > maxx2) {
            maxx2 = op;
            l3 = p;
        }
    }
    vl dis2(n * n + 1);
    rep(i, 1, n * n) dis2[i] = ask(i, l3);
    vvl res(n, vl(n));
    rep(i, 1, n * n) {
        ll x = (dis[i] + dis2[i] - n + 1) / 2;
        ll y = dis[i] - x;
        res[x][y] = i;
    }
    report(res);
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}