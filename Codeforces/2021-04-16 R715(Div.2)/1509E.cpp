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
using i128 = __int128_t;
void solve() {
    ll n, k;
    cin >> n >> k;
    if (n <= 63 && (1LL << (n - 1)) < k) {
        cout << -1 << endl;
        return;
    }
    vl res;
    ll l = 1;
    while (l <= n) {
        ll tem = 1;
        while (tem <= n - l + 1) {
            ll tem2 = n - l + 1 - tem;
            ll cnt;
            if (tem2 == 0)
                cnt = 1;
            else if (tem2 <= 63)
                cnt = (1LL << (tem2 - 1));
            else
                cnt = (1LL << 62);
            if (k > cnt) {
                k -= cnt;
                tem++;
            } else
                break;
        }
        frep(i, l + tem - 1, l) res.push_back(i);
        l += tem;
    }
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
