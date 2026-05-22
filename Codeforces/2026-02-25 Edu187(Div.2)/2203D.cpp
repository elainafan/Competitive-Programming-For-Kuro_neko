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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, m - 1) cin >> b[i];
    ranges::sort(a);
    a.erase(unique(all(a)), a.end());
    vi res(n + m + 1);
    rep(i, 0, sz(a) - 1) {
        for (int j = a[i]; j <= n + m; j += a[i]) {
            res[j]++;
        }
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    rep(i, 0, m - 1) {
        if (res[b[i]] == 0)
            cnt1++;
        else if (res[b[i]] > 0 && res[b[i]] < sz(a))
            cnt2++;
        else if (res[b[i]] == sz(a))
            cnt3++;
    }
    if (cnt2 % 2 == 0) {
        if (cnt3 > cnt1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    } else {
        if (cnt3 >= cnt1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
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