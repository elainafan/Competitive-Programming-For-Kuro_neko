#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
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
#define endl '\n'
using namespace std;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<bool> vis(n + 1, false);
    rep(i, 0, n - 1) {
        if (a[i] != 0) vis[a[i]] = true;
    }
    int re = n;
    rep(i, 0, n - 1) {
        if (a[i]) continue;
        while (re >= 1 && vis[re]) re--;
        a[i] = re;
        vis[re] = true;
    }
    int l = 0, r = n - 1;
    while (l <= n - 1 && a[l] == l + 1) l++;
    while (r >= 0 && a[r] == r + 1) r--;
    if (r <= l)
        cout << 0 << endl;
    else
        cout << r - l + 1 << endl;
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
