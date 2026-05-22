#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    rep(i, 0, n - 1) {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    if (!(cnt0 % 2 == 1 || cnt1 % 2 == 0)) {
        cout << -1 << endl;
        return;
    }
    if (cnt0 % 2 == 1) {
        cout << cnt0 << endl;
        rep(i, 0, n - 1) {
            if (s[i] == '0') cout << i + 1 << ' ';
        }
        cout << endl;
        return;
    }
    cout << cnt1 << endl;
    rep(i, 0, n - 1) {
        if (s[i] == '1') cout << i + 1 << ' ';
    }
    if (cnt1 != 0) cout << endl;
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
