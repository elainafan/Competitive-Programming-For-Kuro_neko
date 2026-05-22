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
    ll n, m;
    cin >> n >> m;
    vvl ma(n, vl(m));
    rep(i, 0, n - 1) { rep(j, 0, m - 1) cin >> ma[i][j]; }
    vector<pll> ma2(m * n);
    rep(i, 0, n - 1) { rep(j, 0, m - 1) ma2[ma[i][j]] = make_pair(i, j); }
    int cnt = 0;
    set<pii> s;
    rep(i, 0, n * m - 1) {
        auto [x, y] = ma2[i];
        auto it = s.lower_bound({x, y});
        if (it != s.end()) {
            if (y > it->second) {
                cout << i << endl;
                return;
            }
        }
        if (it != s.begin()) {
            auto pre = prev(it);
            if (pre->second > y) {
                cout << i << endl;
                return;
            }
        }
        s.insert({x, y});
    }
    cout << m * n << endl;
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
