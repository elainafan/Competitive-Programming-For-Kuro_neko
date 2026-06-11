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
    string s;
    cin >> s;
    int tot0 = 0, tot1 = 0;
    rep(i, 0, n - 1) {
        if (s[i] == 'a')
            tot0++;
        else
            tot1++;
    }
    map<ll, ll> ma;
    ma[0] = -1;
    ll tem = tot0 - tot1;
    if (tem == 0) {
        cout << 0 << endl;
        return;
    }
    ll tem2 = 0;
    ll ans = LLONG_MAX;
    rep(i, 0, n - 1) {
        tem2 += (s[i] == 'a' ? 1 : -1);
        if (ma.find(tem2 - tem) != ma.end()) ans = min(ans, i - ma[tem2 - tem]);
        ma[tem2] = i;
    }
    cout << (ans == n ? -1 : ans) << endl;
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
