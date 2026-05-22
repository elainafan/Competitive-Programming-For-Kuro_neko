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
    int n, m;
    cin >> n >> m;
    vi l(n);
    vvi ma;
    rep(i, 0, n - 1) {
        cin >> l[i];
        vi tem(l[i]);
        rep(j, 0, l[i] - 1) cin >> tem[j];
        ma.push_back(tem);
    }
    vi tem(m + 1);
    int ans = 0;
    rep(i, 0, n - 1) {
        for (int& p : ma[i]) tem[p]++;
    }
    bool pd = true;
    rep(i, 1, m) {
        if (tem[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    rep(i, 0, n - 1) {
        bool flag = true;
        for (int& p : ma[i]) {
            if (tem[p] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    if (ans >= 2)
        cout << "YES" << endl;
    else
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
