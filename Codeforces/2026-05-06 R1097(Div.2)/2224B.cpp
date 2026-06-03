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
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    sort(all2(a));
    sort(a.begin() + 1, a.end());
    ll tem = a[0];
    ll cnt = 0;
    vl cnt2(n + 1);
    ll ans = tem * n;
    rep(i, 1, n - 1) {
        if (a[i] <= n) cnt2[a[i]]++;
    }
    ll tem2 = 1;
    vl vis(n + 2);
    if (tem <= n) vis[tem]++;
    while (cnt <= n && vis[cnt]) cnt++;
    ans += cnt;
    while (tem2 < n) {
        if (cnt <= n && cnt2[cnt]) {
            tem2++;
            cnt2[cnt]--;
            vis[cnt]++;
            while (cnt <= n && vis[cnt]) cnt++;
            ans += cnt;
        } else {
            ans += (n - tem2) * cnt;
            break;
        }
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
