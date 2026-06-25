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
    ll n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;
    deque<char> q;
    rep(i, 0, n - 1) q.push_back(a[i]);
    rep(i, 0, m - 1) {
        if (c[i] == 'V')
            q.push_front(b[i]);
        else
            q.push_back(b[i]);
    }
    string res = "";
    while (!q.empty()) {
        auto node = q.front();
        q.pop_front();
        res.push_back(node);
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
