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
    int l, r;
    cin >> l >> r;
    vi a(r + 1);
    vi b(r + 1);
    int ans = 0;
    int tem = popcount((unsigned)r);
    cout << 1LL * r * (r + 1) << endl;
    if ((1 << tem) == r + 1) {
        rep(i, 0, r) { cout << (r ^ i) << ' '; }
        cout << endl;
        return;
    }
    tem = r;
    while (tem >= 0) {
        int tem2 = 1;
        while (tem2 <= tem) tem2 <<= 1;
        tem2--;
        int len = tem2 - tem;
        rep(i, len, tem) a[i] = tem2 - i;
        tem = len - 1;
    }
    rep(i, 0, r) cout << a[i] << ' ';
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
