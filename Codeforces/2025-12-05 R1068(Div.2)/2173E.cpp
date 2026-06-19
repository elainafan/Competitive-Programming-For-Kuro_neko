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
pll ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll op, op2;
    cin >> op >> op2;
    return {op, op2};
}
void report() {
    cout << "! " << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    vl a(n + 1), pos(n + 1);
    rep(i, 1, n) cin >> a[i], pos[a[i]] = i;
    if (n % 2 == 1) {
        while (pos[(n + 1) / 2] != (n + 1) / 2) {
            auto [x, y] = ask(pos[(n + 1) / 2], (n + 1) / 2);
            swap(a[x], a[y]);
            pos[a[x]] = x;
            pos[a[y]] = y;
        }
    }
    rep(i, 1, n / 2) {
        while (pos[i] + pos[n + 1 - i] != n + 1) {
            auto [x, y] = ask(pos[i], n + 1 - pos[n + 1 - i]);
            swap(a[x], a[y]);
            pos[a[x]] = x;
            pos[a[y]] = y;
        }
    }
    rep(i, 1, n / 2) {
        while (pos[i] != i || pos[n + 1 - i] != n + 1 - i) {
            if (pos[i] != i) {
                auto [x, y] = ask(pos[i], i);
                swap(a[x], a[y]);
                pos[a[x]] = x;
                pos[a[y]] = y;
            }
            if (pos[n + 1 - i] != n + 1 - i) {
                auto [x, y] = ask(pos[n + 1 - i], n + 1 - i);
                swap(a[x], a[y]);
                pos[a[x]] = x;
                pos[a[y]] = y;
            }
        }
    }
    report();
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