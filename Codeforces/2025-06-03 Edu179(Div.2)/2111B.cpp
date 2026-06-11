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
    ll n, m, x, y, z;
    cin >> n >> m;
    vector<trl> ma;
    vl f(n + 1);
    f[1] = 1, f[2] = 2;
    rep(i, 3, n) f[i] = f[i - 1] + f[i - 2];
    string res = "";
    rep(i, 0, m - 1) {
        cin >> x >> y >> z;
        vl tem = {x, y, z};
        ranges::sort(tem);
        if (tem[2] >= f[n] + f[n - 1] && tem[1] >= f[n] && tem[0] >= f[n])
            res.push_back('1');
        else
            res.push_back('0');
    }
    cout << res << endl;
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
