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
    ll n, k;
    cin >> n >> k;
    if (n <= 60 && k > (1LL << n)) {
        cout << -1 << endl;
        return;
    }
    map<ll, ll> ma;
    map<ll, ll> ma2;
    rep(i, 1, k) {
        ll tem = i;
        ll cnt = 0;
        while (tem) {
            cnt++;
            tem /= 10;
        }
        ma[cnt]++;
    }
    i128 tem = 1;
    i128 re = k;
    for (ll i = 0; re > 0; i++) {
        ma2[i] += min(tem, re);
        re -= min(tem, re);
        tem = tem * (n - i) / (i + 1);
    }
    ll ans = 0;
    auto it = ma.rbegin();
    auto it2 = ma2.begin();
    while (it != ma.rend() && it2 != ma.end()) {
        ll tem2 = min(it->second, it2->second);
        ans += tem2 * it->first * it2->first;
        it->second -= tem2, it2->second -= tem2;
        if (it->second == 0) it++;
        if (it2->second == 0) it2++;
    }
    cout << ans << endl;
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
