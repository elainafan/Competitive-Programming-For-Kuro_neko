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
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int mixx = INT_MAX;
    rep(i, x, y - 1) mixx = min(mixx, a[i]);
    int tem = 0;
    rep(i, x, y - 1) {
        if (a[i] == mixx) tem = i - x;
    }
    auto tem2 = a;
    int l = y - x;
    rep(i, x, y - 1) { a[x + (i - x - tem + l) % l] = tem2[i]; }
    bool flag = false;
    rep(i, 0, x - 1) {
        if (a[i] > a[x] && flag == false) {
            flag = true;
            rep(j, x, y - 1) cout << a[j] << ' ';
        }
        cout << a[i] << ' ';
    }
    rep(i, y, n - 1) {
        if (a[i] > a[x] && flag == false) {
            flag = true;
            rep(j, x, y - 1) cout << a[j] << ' ';
        }
        cout << a[i] << ' ';
    }
    if (!flag) {
        rep(i, x, y - 1) cout << a[i] << ' ';
    }
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
