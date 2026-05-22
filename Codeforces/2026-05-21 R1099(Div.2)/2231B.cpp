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
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define endl '\n'
using namespace std;
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vi tem;
    ll tem2 = LLONG_MIN;
    rep(i, 0, n - 2) {
        if (a[i] > a[i + 1]) {
            tem2 = max(tem2, a[i] - a[i + 1]);
        }
    }
    if (tem2 == LLONG_MIN) {
        cout << "YES" << endl;
        return;
    }
    int tem3 = 0;
    rep(i, 0, n - 2) {
        if (a[i] > a[i + 1]) {
            if (tem3) {
                cout << "NO" << endl;
                return;
            }
            tem3 = 1;
        } else {
            if (tem3 && a[i + 1] >= a[i] + tem2) {
                tem3 = 0;
            }
        }
    }
    cout << "YES" << endl;
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