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
    ll tem = log2(n);
    if (n == (1LL << tem) && (k < (1LL << tem) || k >= 2 * (1LL << tem))) {
        cout << "NO" << endl;
        return;
    }
    if (n != (1LL << tem) && k >= 2 * (1LL << tem)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll tem2 = n ^ k;
    vl res(n);
    if (tem2 == 0) {
        rep(i, 1, n - 1) cout << i << ' ';
        cout << 0 << endl;
        return;
    } else if (tem2 < n) {
        rep(i, 1, n - 1) {
            if (i == tem2) continue;
            cout << i << ' ';
        }
        cout << 0 << ' ' << tem2 << endl;
        return;
    } else {
        ll te = (1LL << tem) ^ tem2;
        rep(i, 1, n - 1) {
            if (i == te || (i == (1LL << tem))) continue;
            cout << i << ' ';
        }
        cout << 0 << ' ' << te << ' ' << (1LL << tem) << endl;
        return;
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
