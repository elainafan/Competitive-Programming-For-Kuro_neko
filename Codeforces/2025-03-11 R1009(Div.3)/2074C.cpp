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
    ll x;
    cin >> x;
    bitset<32> d(x);
    int t = log2(x);
    int t2 = log2(x + 1);
    if (x == (1 << t) || x == (1 << t2) - 1) {
        cout << -1 << endl;
        return;
    }
    int idx = -1;
    frep(i, 31, 0) {
        if (d[i]) {
            idx = i;
            break;
        }
    }
    int idx2 = -1;
    rep(i, 0, 31) {
        if (!d[i]) {
            idx2 = i;
            break;
        }
    }
    ll y = x - (1 << idx) + (1 << idx2);
    cout << (y >= x ? -1 : y) << endl;
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
