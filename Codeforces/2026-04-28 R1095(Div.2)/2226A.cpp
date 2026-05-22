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
const ll MOD = 676767677;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int idx = -1;
    rep(i, 0, n - 1) {
        if (a[i] > 1) idx = i;
    }
    if (idx == -1) {
        cout << 1 << endl;
        return;
    }
    ll ans = 0;
    rep(i, 0, n - 1) {
        if (a[i] > 1) {
            ans = (ans + a[i]) % MOD;
        }
    }
    bool flag = false;
    rep(i, idx + 1, n - 1) {
        if (a[i] == 1) {
            flag = true;
            break;
        }
    }
    if (flag) ans = (ans + 1) % MOD;
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
