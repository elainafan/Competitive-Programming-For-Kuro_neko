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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int l, r;
    auto kmp = [&](const string& pattern) -> vi {
        int m = sz(pattern);
        int cnt = 0;
        vi pi(m);
        rep(i, 1, m - 1) {
            char b = pattern[i];
            while (cnt && pattern[cnt] != b) cnt = pi[cnt - 1];
            if (pattern[cnt] == b) cnt++;
            pi[i] = cnt;
        }
        return pi;
    };
    rep(i, 0, q - 1) {
        cin >> l >> r;
        int len = r - l + 1;
        l--;
        string tem = s.substr(l, len);
        auto pi = kmp(tem);
        vi dp(len);
        vi b(len);
        rep(j, 0, len - 1) {
            if (pi[j] == 0)
                b[j] = 0;
            else if (pi[pi[j] - 1] == 0)
                b[j] = pi[j];
            else
                b[j] = b[pi[j] - 1];
        }
        ll ans = 0;
        rep(j, 0, len - 1) {
            if (b[j] == 0)
                dp[j] = 1;
            else
                dp[j] = dp[j - b[j]] + 1;
            ans += dp[j];
        }
        cout << ans << endl;
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
