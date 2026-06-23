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
using i128 = __int128_t;
void solve() {
    ll n;
    cin >> n;
    vvl ma(n, vl(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) cin >> ma[i][j]; }
    vl tem;
    rep(i, 0, n - 1) {
        int tem2 = 0;
        frep(j, n - 1, 0) {
            if (ma[i][j] != 1) break;
            tem2++;
        }
        tem.push_back(tem2);
    }
    int cnt = 0;
    ranges::sort(tem);
    rep(i, 0, n - 1) {
        if (tem[i] >= cnt) cnt++;
    }
    cout << cnt << endl;
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
