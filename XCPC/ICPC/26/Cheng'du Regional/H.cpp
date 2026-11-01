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
void report(vl& res) {
    cout << "! ";
    rep(i, 0, sz(res) - 1) cout << res[i] << ' ';
    cout << '\n';
    cout.flush();
    return;
}
void solve() {
    ll n;
    cin >> n;
    vl res;
    res.push_back(1), res.push_back(2);
    ll idx = -1;
    if (ask(1, 2)) {
        swap(res[0], res[1]), idx = 0;
    }
    rep(i, 3, n) {
        if (idx == -1) {
            ll st = res[0], ed = res[sz(res) - 1];
            if (ask(i, st)) {
                if (ask(i, ed)) {
                    idx = sz(res) - 1;
                    res.push_back(i);
                } else {
                    idx = sz(res) - 2;
                    res.insert(res.end() - 1, i);
                }
            } else {
                if (ask(st, i)) {
                    idx = 0;
                    res.insert(res.begin(), i);
                } else
                    res.insert(res.end() - 1, i);
            }
        } else {
            ll l = res[idx], r = res[idx + 1];
            if (ask(i, l)) {
                if (ask(i, r))
                    res.push_back(i);
                else
                    res.insert(res.begin() + idx + 1, i);
            } else {
                ll st = res[0], ed = res[sz(res) - 1];
                if (ask(i, st))
                    res.insert(res.begin() + idx + 1, i), idx++;
                else
                    res.insert(res.begin(), i), idx++;
            }
        }
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