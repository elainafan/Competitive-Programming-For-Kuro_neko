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
constexpr int MX = 2e5 + 5;
vector<int> divisors[MX];
auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vvi ma(n, vi(m));
    if (m % k == 0) {
        rep(i, 0, n - 1) { rep(j, 0, m - 1) ma[i][j] = (j % k + i) % k + 1; }
    } else if (n % k == 0) {
        rep(i, 0, m - 1) {
            rep(j, 0, n - 1) { ma[j][i] = (j % k + i) % k + 1; }
        }
    } else {
        int idx = -1, idx2 = -1;
        for (int& p : divisors[k]) {
            if (n % p == 0 && m % (k / p) == 0) {
                idx = p, idx2 = k / p;
            }
        }
        rep(i, 0, n - 1) {
            rep(j, 0, m - 1) { ma[i][j] = (i % idx) * idx2 + (j % idx2) + 1; }
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) cout << ma[i][j] << ' ';
        cout << endl;
    }
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
