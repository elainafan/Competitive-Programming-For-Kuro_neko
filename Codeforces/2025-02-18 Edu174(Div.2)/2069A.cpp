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
    vi a(n - 2);
    rep(i, 0, n - 3) cin >> a[i];
    if (n == 3) {
        cout << "YES" << endl;
        return;
    }
    int las = -1;
    int las2 = -1;
    int tem = 0;
    rep(i, 1, n - 4) {
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            cout << "NO" << endl;
            return;
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