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
    ll a, b, x;
    cin >> a >> b >> x;
    vector<pll> tem;
    vector<pll> tem2;
    int cnt = 0;
    while (a != 0) {
        tem.emplace_back(a, cnt);
        a /= x;
        cnt++;
    }
    tem.emplace_back(0, cnt);
    int cnt2 = 0;
    while (b != 0) {
        tem2.emplace_back(b, cnt2);
        b /= x;
        cnt2++;
    }
    tem2.emplace_back(0, cnt2);
    ll ans = LLONG_MAX;
    for (auto& [x, y] : tem) {
        for (auto& [a, b] : tem2) {
            ans = min(ans, y + b + abs(a - x));
        }
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
