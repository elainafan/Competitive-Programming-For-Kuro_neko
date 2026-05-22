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
    ll n, y;
    cin >> n >> y;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::sort(a);
    int maxx = *max_element(all(a));
    if (maxx == 1) {
        cout << n << endl;
        return;
    }
    vl pre(maxx + 1);
    rep(i, 0, n - 1) pre[a[i]]++;
    rep(i, 1, maxx) pre[i] += pre[i - 1];
    vl cnt(maxx + 1);
    rep(i, 0, n - 1) cnt[a[i]]++;
    ll ans = LLONG_MIN;
    rep(i, 2, maxx) {
        ll tem = 0;
        for (int j = i; j < maxx + i; j += i) {
            if (j >= maxx) {
                ll tem2 = pre[maxx] - pre[j - i];
                if (tem2 == 0) continue;
                tem += 1LL * (j / i) * tem2 - y * max(0LL, (tem2 - cnt[(j / i)]));
            } else {
                ll tem2 = pre[j] - pre[j - i];
                if (tem2 == 0) continue;
                tem += 1LL * (j / i) * tem2 - y * max(0LL, (tem2 - cnt[(j / i)]));
            }
        }
        ans = max(ans, tem);
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
