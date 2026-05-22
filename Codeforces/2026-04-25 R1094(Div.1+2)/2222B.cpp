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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
#define endl '\n'
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl b(m);
    rep(i, 0, m - 1) {
        cin >> b[i];
        b[i]--;
    }
    ll ans2 = 0;
    rep(i, 0, n - 1) ans2 += a[i];
    vl tem1;
    vl tem2;
    rep(i, 0, n - 1) {
        if (i % 2 == 0)
            tem1.push_back(a[i]);
        else
            tem2.push_back(a[i]);
    }
    sort(all2(tem1));
    sort(all2(tem2));
    int l = 0, r = 0;
    ll ans = 0;
    rep(i, 0, m - 1) {
        if (b[i] % 2 == 0) {
            if (l < sz(tem1) && tem1[l] >= 0) {
                ans += tem1[l];
                l++;
            } else if (l == 0 && sz(tem1) > 0) {
                ans += tem1[l];
                l++;
            }
        } else {
            if (r < sz(tem2) && tem2[r] >= 0) {
                ans += tem2[r];
                r++;
            } else if (r == 0 && sz(tem2) > 0) {
                ans += tem2[r];
                r++;
            }
        }
    }
    cout << ans2 - ans << endl;
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
