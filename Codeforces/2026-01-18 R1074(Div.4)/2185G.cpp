#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> l(n);
    vector<vector<int>> a(n);
    for (int i = 0; i <= n - 1; i++) {
        cin >> l[i];
        a[i].resize(l[i]);
        for (int j = 0; j < l[i]; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> mex(n, 0);
    ll tot = 0;
    ll ans = 0;
    vector<map<int, int>> ma(n);
    map<int, int> ma2;
    for (int i = 0; i <= n - 1; i++) {
        int cnt = 0;
        for (int& p : a[i]) ma[i][p]++;
        while (ma[i].count(cnt)) cnt++;
        mex[i] = cnt;
        tot += 1LL * cnt;
        int cnt2 = cnt + 1;
        while (ma[i].count(cnt2)) cnt2++;
        ma2[cnt] += cnt2 - cnt;
    }
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= l[i] - 1; j++) {
            if (a[i][j] <= mex[i]) {
                int tem = ma2[a[i][j]];
                if (ma[i][a[i][j]] >= 2) {
                    ans += (n - 1) * tot + 1LL * tem;
                } else {
                    ans += (n - 1) * tot + 1LL * tem;
                    ans -= 1LL * (n - 1) * (mex[i] - a[i][j]);
                }
            } else {
                int tem = ma2[a[i][j]];
                ans += (n - 1) * tot + 1LL * tem;
            }
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