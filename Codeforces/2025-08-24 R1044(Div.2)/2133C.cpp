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
using i128 = __int128_t;
ll ask(ll x, ll k, vl& res) {
    cout << "? " << x << ' ' << k << ' ';
    rep(i, 0, sz(res) - 1) cout << res[i] << ' ';
    cout << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(ll k, vl& res) {
    cout << "! " << k << ' ';
    rep(i, 0, sz(res) - 1) cout << res[i] << ' ';
    cout << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    vl res(n + 1);
    vl tem;
    rep(i, 1, n) tem.push_back(i);
    rep(i, 1, n) res[i] = ask(i, n, tem);
    int idx = -1;
    ll maxx = LLONG_MIN;
    rep(i, 1, n) {
        if (res[i] > maxx) {
            maxx = res[i];
            idx = i;
        }
    }
    vl res2;
    map<ll, vl> ma;
    rep(i, 1, n) { ma[res[i]].push_back(i); }
    res2.push_back(idx);
    while (res[idx] > 1) {
        ll tem2 = -1;
        for (auto& p : ma[res[idx] - 1]) {
            vl tem3;
            tem3.push_back(p);
            tem3.push_back(idx);
            ll op = ask(idx, 2, tem3);
            if (op == 2) {
                tem2 = p;
                break;
            }
        }
        res2.push_back(tem2);
        idx = tem2;
    }
    report(sz(res2), res2);
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
