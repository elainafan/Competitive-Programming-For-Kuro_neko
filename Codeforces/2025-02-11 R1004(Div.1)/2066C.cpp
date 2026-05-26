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
const ll MOD = 1e9 + 7;
ull splitmix64(ull x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

struct custom_hash {
    static const ull FIXED_RANDOM;

    size_t operator()(ull x) const { return splitmix64(x + FIXED_RANDOM); }
};

const ull custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// 如果是 x x x^d 那么，此时异或一个 d 有三种情况
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    umap<ll, ll, custom_hash> ma;
    ma[0] = 1;
    ll tem = 0;
    ll ans = 1;
    rep(i, 0, n - 1) {
        ll tem2 = a[i];
        ll tem3 = 2 * (ma[tem] + ma[tem ^ tem2]) % MOD;
        ma[tem] = (ma[tem] + tem3) % MOD;
        tem ^= tem2;
        ans = (ans + tem3) % MOD;
    }
    cout << ans << endl;
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
