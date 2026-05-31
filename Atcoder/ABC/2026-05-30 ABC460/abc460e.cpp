#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define i128 __int128
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
const ll MOD = 998244353;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<i128> tem(20);
    tem[0] = 1;
    rep(i, 1, 19) tem[i] = tem[i - 1] * 10;
    ll ans = 0;
    rep(i, 1, 19) {
        ll tem2 = max((i128)0, min((i128)n, tem[i] - 1) - tem[i - 1] + 1);
        ll tem3 = (tem[i] - 1) % m;
        ans = (ans + tem2 % MOD * ((n / (m / __gcd(m, tem3)))%MOD) % MOD) % MOD;
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
