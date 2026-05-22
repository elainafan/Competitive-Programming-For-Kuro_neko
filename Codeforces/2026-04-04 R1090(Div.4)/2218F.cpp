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
    int x, y;
    cin >> x >> y;
    int n = x + y;
    vvi ma(n);
    if (x > y) {
        cout << "NO" << endl;
        return;
    }
    if (n % 2 == 0 && x == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n % 2 == 0) {
        x--;
        for (int i = 1; i <= 2 * x; i += 2) {
            ma[0].push_back(i);
            ma[i].push_back(i + 1);
        }
        rep(i, 2 * x + 1, n - 1) ma[0].push_back(i);
    } else if (n % 2 == 1) {
        y--;
        for (int i = 1; i <= 2 * x; i += 2) {
            ma[0].push_back(i);
            ma[i].push_back(i + 1);
        }
        rep(i, 2 * x + 1, n - 1) ma[0].push_back(i);
    }
    rep(i, 0, n - 1) {
        for (int& p : ma[i]) cout << i + 1 << ' ' << p + 1 << endl;
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
