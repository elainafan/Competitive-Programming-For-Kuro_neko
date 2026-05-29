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
    vl l(n);
    vvl ma(n);
    rep(i, 0, n - 1) {
        cin >> l[i];
        ma[i].resize(l[i]);
        rep(j, 0, l[i] - 1) cin >> ma[i][j];
    }
    ll maxx = *max_element(all(l));
    vl ans(maxx);
    ll tem = 0;
    auto check = [&](ll x, ll y) -> bool {
        ll tem2 = min(sz(ma[x]), sz(ma[y]));
        rep(i, tem, tem2 - 1) {
            if (ma[x][i] < ma[y][i]) return true;
            if (ma[x][i] > ma[y][i]) return false;
        }
        return l[x] <= l[y];
    };
    while (tem < maxx) {
        ll idx = -1;
        rep(i, 0, n - 1) {
            if (l[i] <= tem) continue;
            if (idx == -1 || check(i, idx)) {
                idx = i;
            }
        }
        rep(i, tem, l[idx] - 1) ans[i] = ma[idx][i];
        tem = l[idx];
    }
    rep(i, 0, maxx - 1) cout << ans[i] << ' ';
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
