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
    ll k, x;
    cin >> k >> x;
    vl ans;
    auto dfs = [&](this auto&& dfs, ll mid) -> void {
        if (mid == (1LL << k))
            return;
        else if (mid < (1LL << k)) {
            ans.push_back(1);
            dfs(mid * 2);
        } else {
            ans.push_back(2);
            dfs(2 * mid - (1LL << (k + 1)));
        }
        return;
    };
    dfs(x);
    ranges::reverse(ans);
    cout << sz(ans) << endl;
    for (auto& p : ans) cout << p << ' ';
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
