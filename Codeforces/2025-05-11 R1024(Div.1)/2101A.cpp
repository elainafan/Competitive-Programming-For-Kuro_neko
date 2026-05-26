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
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
void solve() {
    int n;
    cin >> n;
    vvi ma(n, vi(n, -1));
    int l, r;
    if (n % 2 == 1)
        l = r = n / 2;
    else
        l = r = n / 2 - 1;
    ma[l][r] = 0;
    int val = 1;
    int tem = 1;
    while (val < n * n) {
        rep(i, 0, 3) {
            rep(j, 1, tem) {
                l += dx[i], r += dy[i];
                if (l >= 0 && l <= n - 1 && r >= 0 && r <= n - 1 && ma[l][r] == -1) ma[l][r] = val++;
                if (val >= n * n) break;
            }
            if (val >= n * n) break;
            if (i % 2 == 1) tem++;
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { cout << ma[i][j] << ' '; }
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
