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
    ll n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    if (n == 3) {
        cout << 1 << ' ' << 3 << endl;
        cout << 2 << ' ' << 3 << endl;
        return;
    }
    if (n == 4) {
        cout << 1 << ' ' << 2 << endl;
        cout << 3 << ' ' << 1 << endl;
        cout << 4 << ' ' << 1 << endl;
        return ;
    }
    vvi ma(n + 1);
    ma[1].push_back(2);
    ma[1].push_back(5);
    ma[2].push_back(3);
    ma[3].push_back(4);
    rep(i, 6, n) {
        ma[1].pop_back();
        ma[2].push_back(i - 1);
        ma[1].push_back(i);
    }
    rep(i, 1, n) {
        for (auto& p : ma[i]) cout << i << ' ' << p << endl;
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
