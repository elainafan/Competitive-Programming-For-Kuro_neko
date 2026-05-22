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
    ll x, y;
    cin >> n >> x >> y;
    x = abs(x), y = abs(y);
    string s;
    cin >> s;
    ll tem1 = 0, tem2 = 0;
    ll res1 = x + y, res2 = x - y;
    int tot1 = 0, tot2 = 0;
    rep(i, 0, n - 1) {
        if (s[i] == '4') {
            tot1++;
        } else {
            tot2++;
        }
    }
    if (tot1 + tot2 >= max(x, y) && x + y <= tot1 + 2 * tot2) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
