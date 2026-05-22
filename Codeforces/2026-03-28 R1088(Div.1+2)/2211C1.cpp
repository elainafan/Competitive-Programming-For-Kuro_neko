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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vi b(n);
    rep(i, 0, n - 1) cin >> b[i];
    rep(i, 0, n - k - 1) {
        if (a[i] != b[i] && b[i] != -1) {
            cout << "NO" << endl;
            return;
        }
    }
    rep(i, k, n - 1) {
        if (a[i] != b[i] && b[i] != -1) {
            cout << "NO" << endl;
            return;
        }
    }
    map<int, int> ma;
    map<int, int> ma2;
    int tot = 0;
    rep(i, n - k, k - 1) { ma[a[i]]++; }
    rep(i, n - k, k - 1) {
        if (b[i] == -1)
            tot++;
        else
            ma2[b[i]]++;
        if (b[i] != -1 && !ma.count(b[i])) {
            cout << "NO" << endl;
            return;
        }
    }
    if (sz(ma2) + tot != sz(ma)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
