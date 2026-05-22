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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 1LL * n * (n + 1) / 2;
    ll tem = 0;
    vi l(n, -1);
    stack<int> s;
    rep(i, 0, n - 1) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (!s.empty()) l[i] = s.top();
        s.push(i);
    }
    int las = 0;
    vi l2(n, 0);
    rep(i, 1, n - 1) {
        if (a[i] > a[i - 1] + 1) {
            las = i;
        }
        l2[i] = las;
    }
    rep(i, 1, n - 1) {
        int tem = (l2[i] > l[i]) ? i : (i - l[i] - 1);
        ans += 1LL * tem * (n - i);
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
