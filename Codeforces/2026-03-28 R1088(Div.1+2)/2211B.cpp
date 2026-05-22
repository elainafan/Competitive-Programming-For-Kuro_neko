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
const int MOD = 676767677;
void solve() {
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 1 << endl;
        rep(i, 0, x - 1) cout << 1 << ' ';
        rep(i, 0, y - 1) cout << -1 << ' ';
        cout << endl;
        return;
    }
    int ans = x - y;
    int tot = 0;
    for (int i = 1; i * i <= abs(ans); i++) {
        if (abs(ans) % i == 0) {
            if (abs(ans) == i * i)
                tot++;
            else
                tot += 2;
        }
    }
    cout << tot << endl;
    if (x < y) {
        rep(i, 0, x - 1) cout << 1 << ' ';
        rep(i, 0, y - 1) cout << -1 << ' ';
        cout << endl;
    } else {
        rep(i, 0, y - 1) cout << -1 << ' ';
        rep(i, 0, x - 1) cout << 1 << ' ';
        cout << endl;
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
