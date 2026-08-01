#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using i128 = __int128_t;
void solve() {
    ll n, k;
    cin >> n >> k;
    if (k % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    if (k < 2 * (n - 1) || k > n * n / 2) {
        cout << -1 << endl;
        return;
    }
    vl res(n);
    ll tem = (k - 2 * (n - 1)) / 2;
    ll l = 0, r = n - 1;
    ll idx = 0;
    while (l <= r) {
        if (r > l + 1 && tem >= (r - l - 2)) {
            res[idx] = l, res[idx + 1] = r;
            idx += 2;
            tem -= (r - l - 2);
            l++, r--;
        } else if (tem == 0) {
            rep(i, l, r) res[idx++] = i;
            break;
        } else {
            rep(i, l, r - tem - 2) res[idx++] = i;
            res[idx++] = r;
            rep(i, r - tem - 1, r - 1) res[idx++] = i;
            break;
        }
    }
    vl id(n);
    rep(i, 0, n - 1) id[res[i]] = i + 1;
    rep(i, 0, n - 2) cout << id[i] << ' ' << id[i + 1] << endl;
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
