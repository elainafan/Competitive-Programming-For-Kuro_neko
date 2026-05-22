#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
constexpr int M = 2e7;
bool is_prime[M];
vector<int> primes;
auto init = [] {
    ranges::fill(is_prime, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < M; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < M; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return 0;
}();
// 函数指针在创建时自动调用
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) { a[i] = 1LL * primes[i] * primes[i + 1]; }
    rep(i, 0, n - 1) cout << a[i] << ' ';
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
