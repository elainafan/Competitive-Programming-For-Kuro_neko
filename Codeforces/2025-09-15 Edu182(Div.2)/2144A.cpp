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
    frep(r, n - 2, 1) {
        rep(l, 0, r - 1) {
            int ans1 = 0;
            int ans2 = 0;
            int ans3 = 0;
            rep(v, 0, l) ans1 = (ans1 + a[v]) % 3;
            rep(v, l + 1, r) ans2 = (ans2 + a[v]) % 3;
            rep(v, r + 1, n - 1) ans3 = (ans3 + a[v]) % 3;
            if (ans1 == ans2 && ans2 == ans3) {
                cout << l + 1 << ' ' << r + 1 << endl;
                return;
            }
            if (ans1 != ans2 && ans1 != ans3 && ans2 != ans3) {
                cout << l + 1 << ' ' << r + 1 << endl;
                return;
            }
        }
    }
    cout << 0 << ' ' << 0 << endl;
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
