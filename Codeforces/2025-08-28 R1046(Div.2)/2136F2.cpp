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
ll ask(ll k, vl& res) {
    cout << "? " << k << ' ';
    rep(i, 0, k - 1) cout << res[i] << ' ';
    cout << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(ll a) {
    cout << "! " << a << '\n';
    cout.flush();
}
void solve() {
    vl tem;
    ll B = 125, N = 8108;
    rep(i, 1, N) tem.push_back(B);
    ll op = ask(sz(tem), tem);
    if (op == 0) {
        vl tem2;
        rep(i, 1, B * B) tem2.push_back(1);
        ll op2 = ask(sz(tem2), tem2);
        ll res = (B * B - 1) / (op2 - 1);
        report(res);
        return;
    } else {
        ll l = (N + op - 1) / op * B, r = min(((N - 1) / (op - 1) + 1) * B - 1, 100000LL);
        vl tem2;
        rep(i, 1, r - l + 1) {
            tem2.push_back(l);
            tem2.push_back(i);
        }
        ll op2 = ask(sz(tem2), tem2);
        ll res = l + 2 * (r - l + 1) - op2;
        report(res);
    }
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