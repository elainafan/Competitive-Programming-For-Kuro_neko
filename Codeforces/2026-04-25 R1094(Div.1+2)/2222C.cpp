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
struct Mid {
    vi cnt;
    int res = 0;
    int cnt2 = 0;
    int l = 0;
    Mid(int x) : cnt(x, 0) {}

    void insert(int x) {
        l++;
        cnt[x]++;
        if (l == 1) {
            res = x;
            cnt2 = 1;
            return;
        }
        if (x <= res) cnt2++;
        int tem = (l + 1) / 2;
        while (res > 0 && cnt2 - cnt[res] >= tem) {
            cnt2 -= cnt[res];
            res--;
        }
        while (res < sz(cnt) - 1 && cnt2 < tem) {
            res++;
            cnt2 += cnt[res];
        }
    }
    int get() { return res; }
};
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int ans = 1;
    auto sorted = a;
    ranges::sort(sorted);
    sorted.erase(unique(all(sorted)), sorted.end());
    rep(i, 0, n - 1) {
        auto x = ranges::lower_bound(sorted, a[i]);
        a[i] = x - sorted.begin();
    }
    int m = sz(sorted);
    vvi dp(n + 1, vi(m, -1));
    rep(i, 0, m - 1) dp[0][i] = 0;
    rep(i, 0, n - 1) {
        Mid tem(m);
        rep(j, i, n - 1) {
            tem.insert(a[j]);
            if ((j - i + 1) % 2 == 0) continue;
            int mid = tem.get();
            if (dp[i][mid] != -1) dp[j + 1][mid] = max(dp[j + 1][mid], dp[i][mid] + 1);
        }
    }
    rep(i, 0, m - 1) { ans = max(ans, dp[n][i]); }
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
