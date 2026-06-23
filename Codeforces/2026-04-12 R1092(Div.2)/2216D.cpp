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
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 2; i * i * i <= n; i++) {
        ll tem = n;
        vl tem2;
        while (tem) {
            tem2.push_back(tem % i);
            tem /= i;
        }
        ll m = sz(tem2);
        rep(j, 2, m) {
            if (m % j != 0) continue;
            bool flag = true;
            for (ll v = 0; v <= m - 1; v += j) {
                rep(l, v + 1, v + j - 1) {
                    if (tem2[l] != tem2[l - 1]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            ans += flag;
        }
    }
    for (ll i = 2; i * i <= n; i++) {
        if (i * i * i <= n) continue;
        ll tem2 = i * i + i + 1;
        if (n % tem2 == 0 && n / tem2 < i) ans++;
    }
    for (ll i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        ll tem = i;
        if (tem >= 3 && n / (tem - 1) < tem - 1) ans++;
        if (tem * tem != n && n / tem >= 3 && n / (n / tem - 1) < n / tem) ans++;
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
