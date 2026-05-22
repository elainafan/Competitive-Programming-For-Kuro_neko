#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    ll x;
    cin >> x;
    vi res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    int tem = reduce(all(res), 0);
    if (tem >= 0 && tem <= 9) {
        cout << 0 << endl;
        return;
    }
    int re = tem - 9;
    auto res2 = res;
    res[sz(res) - 1]--;
    sort(all2(res));
    int tem2 = 0;
    int ans = INT_MAX;
    rep(i, 0, sz(res) - 1) {
        tem2 += res[i];
        if (tem2 >= re) {
            ans = min(ans, i + 1);
            break;
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
