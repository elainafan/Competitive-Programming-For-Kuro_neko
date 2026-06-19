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
    string s;
    cin >> s;
    vl ma(3);
    ll tem = 0;
    ma[0] = 1;
    ll ans = 0;
    rep(i, 0, n - 1) {
        tem += (s[i] == '0' ? 1 : -1);
        tem = (tem + 3) % 3;
        ans += 1LL * (i + 1) - ma[tem];
        ma[tem]++;
    }
    ll tem2 = 1;
    rep(i, 1, n - 1) {
        if (s[i] != s[i - 1]) {
            tem2++;
        } else {
            if (tem2 <= 2)
                tem2 = 1;
            else {
                if (tem2 % 2 == 0)
                    ans -= (tem2 / 2 - 1) * tem2 / 2;
                else
                    ans -= (tem2 / 2) * (tem2 / 2);
                tem2 = 1;
            }
        }
    }
    if (tem2 >= 3) {
        if (tem2 % 2 == 0)
            ans -= (tem2 / 2 - 1) * tem2 / 2;
        else
            ans -= (tem2 / 2) * (tem2 / 2);
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
