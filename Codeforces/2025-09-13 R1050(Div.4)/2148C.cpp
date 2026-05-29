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
    ll n, m;
    cin >> n >> m;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    ll ans = 0;
    rep(i, 0, n - 1) {
        if (i == 0) {
            if (ma[i].first > 0) {
                if (ma[i].first % 2 != ma[i].second)
                    ans += ma[i].first - 1;
                else
                    ans += ma[i].first;
            }
        }
        if (i == n - 1) {
            ans += m - ma[i].first;
        } else {
            int tem = (ma[i + 1].first - ma[i].first) % 2;
            int tem2 = ma[i + 1].second ^ ma[i].second;
            if (tem != tem2)
                ans += ma[i + 1].first - ma[i].first - 1;
            else
                ans += ma[i + 1].first - ma[i].first;
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
