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
    ll n, k;
    cin >> n >> k;
    vl l(n);
    vvl ma(n);
    rep(i, 0, n - 1) {
        cin >> l[i];
        ma[i].resize(l[i]);
        rep(j, 0, l[i] - 1) cin >> ma[i][j];
    }
    vl c(n);
    rep(i, 0, n - 1) cin >> c[i];
    vl pre(n);
    pre[0] = c[0] * l[0];
    rep(i, 1, n - 1) pre[i] = pre[i - 1] + c[i] * l[i];
    int tem = ranges::lower_bound(pre, k) - pre.begin();
    ll tem2 = 0;
    if (tem > 0)
        tem2 = k - pre[tem - 1] - 1;
    else
        tem2 = k - 1;
    cout << ma[tem][tem2 % l[tem]] << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}