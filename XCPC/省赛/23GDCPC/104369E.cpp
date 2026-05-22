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
    int n, k;
    cin >> n >> k;
    vector<string> ma(n);
    rep(i, 0, n - 1) cin >> ma[i];
    ranges::sort(ma);
    vector<string> ma2;
    auto lcp = [&](const string& x, const string& y) -> string {
        int tem = min(sz(x), sz(y));
        int cnt = 0;
        while (cnt < tem && x[cnt] == y[cnt]) cnt++;
        return x.substr(0, cnt);
    };
    ma2.push_back("");
    rep(i, 1, n - 1) { ma2.push_back(lcp(ma[i], ma[i - 1])); }
    ranges::sort(ma2);
    ma2.erase(unique(all(ma2)), ma2.end());
    int m = sz(ma2);
    int l = 0, r = m - 1, mid, ans = 0;
    auto check = [&](int mid) -> bool {
        int cnt = 0;
        int tem = 0;
        while (tem < n) {
            cnt++;
            if (cnt >= k) return true;
            if (ma[tem] <= ma2[mid]) {
                tem++;
                continue;
            }
            int tem2 = 0;
            int tem3 = min(sz(ma[tem]), sz(ma2[mid]));
            while (tem2 < tem3 && ma[tem][tem2] == ma2[mid][tem2]) tem2++;
            string tem4 = ma[tem].substr(0, tem2 + 1);
            int tem5 = ranges::lower_bound(ma, tem4 + (char)(127)) - ma.begin();
            tem = tem5;
        }
        return false;
    };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << (ans == 0 ? "EMPTY" : ma2[ans]) << endl;
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
