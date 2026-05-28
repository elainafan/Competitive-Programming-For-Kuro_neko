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
    ll n, st, en, x, y;
    cin >> n >> st >> en;
    st--, en--;
    vvi ma(n);
    rep(i, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vi dis(n, -1);
    dis[en] = 0;
    queue<int> q;
    q.push(en);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int& p : ma[node]) {
            if (dis[p] == -1) {
                dis[p] = dis[node] + 1;
                q.push(p);
            }
        }
    }
    vector<pii> ma2;
    rep(i, 0, n - 1) ma2.emplace_back(dis[i], i + 1);
    sort(all(ma2), [&](const pii& x, const pii& y) { return x.first > y.first; });
    rep(i, 0, n - 1) cout << ma2[i].second << ' ';
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
