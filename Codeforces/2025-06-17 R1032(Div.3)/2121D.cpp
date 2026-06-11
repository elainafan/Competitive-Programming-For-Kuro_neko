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
void solve() {
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    vector<pll> res;
    rep(i, 0, n - 2) {
        rep(j, 0, n - 2) {
            if (a[j] > a[j + 1]) {
                res.emplace_back(1, j + 1);
                swap(a[j], a[j + 1]);
            }
        }
    }
    rep(i, 0, n - 2) {
        rep(j, 0, n - 2) {
            if (b[j] > b[j + 1]) {
                res.emplace_back(2, j + 1);
                swap(b[j], b[j + 1]);
            }
        }
    }
    frep(i, n - 1, 0) {
        if (a[i] >= b[i]) {
            res.emplace_back(3, i + 1);
            swap(a[i], b[i]);
        }
    }
    cout << sz(res) << endl;
    for (auto& p : res) cout << p.first << ' ' << p.second << endl;
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
