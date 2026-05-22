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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vi p(k);
    rep(i, 0, k - 1) {
        cin >> p[i];
        p[i]--;
    }
    vi tem;
    rep(i, 0, k - 1) {
        if (i == 0) {
            int ans = 0;
            frep(j, p[i] - 1, 0) {
                if (a[j] != a[p[i]] && a[j] != a[j + 1]) ans++;
            }
            tem.push_back(ans);
        }
        if (i == k - 1) {
            int ans = 0;
            rep(j, p[i] + 1, n - 1) {
                if (a[j] != a[p[i]] && a[j] != a[j - 1]) ans++;
            }
            tem.push_back(ans);
        } else {
            int idx = p[i], idx2 = p[i + 1];
            int ans = 0;
            int ans2 = 0;
            rep(j, p[i] + 1, p[i + 1]) {
                if (a[j] != a[p[i]] && a[j] != a[j - 1]) ans++;
            }
            tem.push_back(ans);
        }
    }
    int ans = 0;
    int maxx = 0;
    rep(i, 0, k) {
        ans += tem[i];
        maxx = max(maxx, tem[i]);
    }
    cout << max(ans, maxx * 2) << endl;
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
