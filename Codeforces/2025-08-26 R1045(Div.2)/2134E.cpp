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
void swap(ll r) {
    cout << "swap " << r << '\n';
    cout.flush();
    return;
}
ll th(ll r) {
    cout << "throw " << r << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(vl& res) {
    cout << "! ";
    rep(i, 1, sz(res) - 1) cout << res[i] << ' ';
    cout << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    vl res(n + 1);
    vl dp(n + 3);
    ll op;
    op = th(n - 1);
    res[n - 1] = (op == 2 ? 1 : 2);
    swap(n - 1);
    op = th(n - 1);
    res[n] = (op == 2 ? 1 : 2);
    dp[n] = 1, dp[n - 1] = op;
    for (ll i = n - 2; i >= 1;) {
        if (dp[i + 1] != dp[i + 2]) {
            op = th(i);
            if (op == dp[i + 1] + 1)
                res[i] = 1;
            else
                res[i] = 2;
            dp[i] = op;
            i--;
        } else {
            if (i == 1) {
                swap(1);
                op = th(2);
                if (op == dp[3] + 1)
                    res[1] = 1;
                else
                    res[1] = 2;
                break;
            } else {
                op = th(i - 1);
                if (op == dp[i + 1] + 2)
                    res[i - 1] = 1;
                else
                    res[i - 1] = 2;
                swap(i - 1);
                op = th(i - 1);
                if (op == dp[i + 1] + 2)
                    res[i] = 1;
                else
                    res[i] = 2;
                dp[i] = dp[i + 1] + 1;
                dp[i - 1] = op;
                i -= 2;
            }
        }
    }
    report(res);
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
