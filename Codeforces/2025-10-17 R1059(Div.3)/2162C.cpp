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
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return ;
    }
    int idx1 = -1, idx2 = -1;
    frep(i, 30, 0) {
        if (a >> i & 1) {
            idx1 = i;
            break;
        }
    }
    frep(i, 30, 0) {
        if (b >> i & 1) {
            idx2 = i;
            break;
        }
    }
    if (idx1 < idx2) {
        cout << -1 << endl;
        return;
    }
    vl res;
    frep(i, idx1, 0) {
        if ((a >> i & 1) != (b >> i & 1)) {
            res.push_back(1LL << i);
        }
    }
    ranges::reverse(res);
    cout << sz(res) << endl;
    for (auto& p : res) cout << p << ' ';
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
