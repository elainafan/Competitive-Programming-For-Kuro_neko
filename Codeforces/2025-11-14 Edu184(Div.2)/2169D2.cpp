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
void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    if (y == 1) {
        cout << -1 << endl;
        return;
    }
    for (ll i = 0; i < x;) {
        ll tem = (k - 1) / (y - 1);
        if (tem == 0) break;
        ll R = (tem + 1) * (y - 1) + 1;
        ll cnt = (R - k + tem - 1) / tem;
        k += min(cnt, x - i) * tem;
        i += min(cnt, x - i);
        if (k > 1e12) {
            cout << -1 << endl;
            return;
        }
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
