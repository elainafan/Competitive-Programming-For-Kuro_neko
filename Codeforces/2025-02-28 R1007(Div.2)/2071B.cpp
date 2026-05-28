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
    ll tem = n * (n + 1) / 2;
    ll tem2 = (ll)sqrt(tem);
    if (tem2 * tem2 == tem) {
        cout << -1 << endl;
        return;
    }
    vl res(n);
    rep(i, 0, n - 1) res[i] = i + 1;
    tem2 = 0;
    rep(i, 0, n - 2) {
        tem2 += res[i];
        ll tem3 = (ll)sqrt(tem2);
        if (tem3 * tem3 == tem2) {
            tem2 = tem2 - res[i] + res[i + 1];
            swap(res[i], res[i + 1]);
        }
    }
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
