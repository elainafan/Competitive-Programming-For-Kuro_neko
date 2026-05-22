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
constexpr int M = 1e5 + 5;
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
constexpr int MOD = 1e9 + 7;
ll mul(ll x, ll y) { return x * 1LL * y % MOD; }
ll qpow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD
void solve() {
    int n, nn;
    cin >> n;
    nn = n;
    auto check = [&](int x) -> bool {
        if (x == 2 || x == 3) return true;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    };
    vector<pii> res;
    for (auto& x : primes) {
        if (x > n) break;
        if (n % x != 0) continue;
        int cnt = 0;
        while (n % x == 0) {
            cnt++;
            n /= x;
        }
        res.emplace_back(x, cnt);
    }
    if (n > 1) res.emplace_back(n, 1);
    ll k = 1;
    for (auto& [x, y] : res) {
        if (y % nn == 0)
            k *= qpow(x, y / nn);
        else
            k *= qpow(x, y / nn + 1);
    }
    cout << k << endl;
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
