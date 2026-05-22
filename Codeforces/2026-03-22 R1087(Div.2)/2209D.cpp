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
    int r, g, b;
    cin >> r >> g >> b;
    string res = "";
    vector<pair<char, int>> ma;
    int ans = r + g + b;
    ma.emplace_back('R', r);
    ma.emplace_back('G', g);
    ma.emplace_back('B', b);
    sort(all(ma), [&](const pair<char, int>& x, const pair<char, int>& y) { return x.second > y.second; });
    rep(t, 1, ans) {
        vector<bool> vis(3, true);
        if (t >= 2) {
            rep(i, 0, 2) {
                if (ma[i].first == res[sz(res) - 1]) vis[i] = false;
            }
        }
        if (t >= 4) {
            rep(i, 0, 2) {
                if (ma[i].first == res[sz(res) - 3]) vis[i] = false;
            }
        }
        int idx = -1;
        rep(i, 0, 2) {
            if (!vis[i] || !ma[i].second) continue;
            if (idx == -1) {
                idx = i;
                continue;
            }
            if (ma[idx].second == ma[i].second) {
                if (sz(res) >= 2 && ma[i].first == res[sz(res) - 2]) idx = i;
            }
        }
        if (idx == -1) break;
        res.push_back(ma[idx].first);
        ma[idx].second--;
        sort(all(ma), [&](const pair<char, int>& x, const pair<char, int>& y) { return x.second > y.second; });
    }
    cout << res << endl;
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
