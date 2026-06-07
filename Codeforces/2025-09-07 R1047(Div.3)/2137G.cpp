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
    ll n, m, q, x, y;
    cin >> n >> m >> q;
    vvl ma(n);
    vvl ma2(n);
    vl deg(n);
    rep(i, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        deg[x - 1]++;
        ma2[y - 1].push_back(x - 1);
    }
    vector<array<ll, 2>> dp(n), cnt(n);
    rep(i, 0, n - 1) { dp[i] = {1, 1}, cnt[i] = {deg[i], deg[i]}; }
    rep(i, 0, q - 1) {
        cin >> x >> y;
        y--;
        if (x == 1) {
            queue<pll> q;
            if (dp[y][0]) {
                dp[y][0] = 0;
                q.emplace(0, y);
            }
            if (dp[y][1]) {
                dp[y][1] = 0;
                q.emplace(1, y);
            }
            while (!q.empty()) {
                auto [op, st] = q.front();
                q.pop();
                for (auto& p : ma2[st]) {
                    cnt[p][op]--;
                    if (op == 0) {
                        if (dp[p][1]) {
                            dp[p][1] = 0;
                            q.emplace(1, p);
                        }
                    } else {
                        if (dp[p][0] && deg[p] > 0 && cnt[p][op] == 0) {
                            dp[p][0] = 0;
                            q.emplace(0, p);
                        }
                    }
                }
            }
        } else {
            cout << (dp[y][0] ? "YES" : "NO") << endl;
        }
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
