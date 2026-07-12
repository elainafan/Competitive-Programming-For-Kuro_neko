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
    ll n;
    cin >> n;
    vl pa(n);
    vvl ma(n);
    rep(i, 1, n - 1) {
        cin >> pa[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
        ma[i].push_back(pa[i]);
    }
    ll ans = 0;
    auto dfs = [&](this auto&& dfs, int x, int pa) -> ll {
        ll tem1 = 0, tem2 = 0;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            auto tem3 = dfs(p, x) + 1;
            if (tem3 >= tem1) {
                tem2 = tem1, tem1 = tem3;
            } else if (tem3 > tem2) {
                tem2 = tem3;
            }
        }
        ans += tem2 + 1;
        return tem1;
    };
    dfs(0, -1);
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
