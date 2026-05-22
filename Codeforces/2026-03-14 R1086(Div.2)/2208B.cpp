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
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int ans = 0;
    int tot = a[p];
    int tem = 0;
    a[p] = -1;
    deque<int> d;
    priority_queue<int, vector<int>, greater<>> q;
    rep(i, 0, k - 1) q.push(a[i]);
    rep(i, k, n - 1) d.push_back(a[i]);
    while (tem <= m) {
        auto node = q.top();
        q.pop();
        if (node == -1) {
            if (tem + tot > m) break;
            ans++;
            tem += tot;
            d.push_back(-1);
            auto tem2 = d.front();
            d.pop_front();
            q.push(tem2);
        } else {
            if (tem + node > m) break;
            tem += node;
            d.push_back(node);
            auto tem2 = d.front();
            d.pop_front();
            q.push(tem2);
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
