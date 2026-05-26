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
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int idx = -1;
    rep(i, 0, n - 1) {
        if (a[i] == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << n << endl;
        return;
    }
    int tot = 0;
    rep(i, 0, n - 1) tot += (a[i] > 0);
    vi suf(n);
    vi vis(n + 2);
    vis[0] = 1;
    int cnt = 1;
    frep(i, n - 1, 0) {
        suf[i] = cnt;
        if (a[i] > 0 && a[i] <= n) {
            vis[a[i]] = 1;
            while (vis[cnt]) cnt++;
        }
    }
    ll mixx = INT_MAX;
    bool flag = true;
    bool flag2 = false;
    rep(i, 0, n - 1) {
        if (a[i] == 0) {
            if (flag) flag2 = true;
        } else {
            mixx = min(mixx, a[i]);
            if (mixx < suf[i]) flag = false;
        }
    }
    cout << tot + flag2 << endl;
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
