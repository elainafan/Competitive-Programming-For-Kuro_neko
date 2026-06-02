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
constexpr int MX = 5e5 + 5;
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
    ll n, m, q, op, x, y;
    cin >> n >> m >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i], a[i] = a[i] % m;
    map<ll, ll> ma;
    for (auto p : divisors[m]) {
        rep(i, 0, n - 2) {
            if (a[i] % p > a[i + 1] % p) ma[p]++;
        }
    }
    rep(i, 0, q - 1) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            x--;
            for (auto& p : divisors[m]) {
                if (x > 0 && a[x] % p < a[x - 1] % p) ma[p]--;
                if (x < n - 1 && a[x] % p > a[x + 1] % p) ma[p]--;
            }
            a[x] = y % m;
            for (auto& p : divisors[m]) {
                if (x > 0 && a[x] % p < a[x - 1] % p) ma[p]++;
                if (x < n - 1 && a[x] % p > a[x + 1] % p) ma[p]++;
            }
        } else {
            cin >> x;
            ll tem = __gcd(x, m);
            if (ma[tem] < m / tem)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
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
