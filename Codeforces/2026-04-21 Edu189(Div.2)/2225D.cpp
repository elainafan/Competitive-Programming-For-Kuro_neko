#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
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
#define endl '\n'
using namespace std;
const ll MOD = 998244353;
void solve() {
    ll n, x;
    cin >> n >> x;
    ll tem = (1 + x / 4) % MOD;
    ll tem2 = (x + 2) / 4 % MOD;
    ll tem3 = (1 + (n + 1) / 4 - tem + MOD) % MOD;
    ll tem4 = ((n + 3) / 4 - tem2 + MOD) % MOD;
    cout << (tem * tem3 % MOD + tem2 * tem4 % MOD) % MOD << endl;
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
