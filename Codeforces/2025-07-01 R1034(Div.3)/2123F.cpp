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
constexpr int MX = 1e5 + 1;
bool pd[MX];
vi primes;
int minp[MX];
auto init = [] {
    rep(i, 2, MX - 1) {
        if (!pd[i]) {
            primes.push_back(i);
            minp[i] = i;
        }
        for (int& p : primes) {
            if (1LL * p * i >= MX) break;
            pd[i * p] = true;
            minp[i * p] = max(minp[i], p);
            if (i % p == 0) break;
        }
    }
    return 0;
}();
void solve() {
    ll n;
    cin >> n;
    vl a(n + 1);
    a[1] = 1;
    ll cnt = 0;
    map<ll, vl> ma;
    rep(i, 2, n) { ma[minp[i]].push_back(i); }
    for (auto& [x, y] : ma) {
        int m = sz(y);
        rep(i, 0, m - 1) { a[y[(i + 1) % m]] = y[i]; }
    }
    rep(i, 1, n) cout << a[i] << ' ';
    cout << endl;
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
