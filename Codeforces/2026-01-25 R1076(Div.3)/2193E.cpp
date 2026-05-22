#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    vector<int> b;
    for (int& p : a) {
        if (p != 1) b.push_back(p);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> dp(n + 1, -1);
    queue<int> q;
    for (int& p : b) {
        q.push(p);
        dp[p] = 1;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int& p : b) {
            ll tem = 1LL * x * p;
            if (tem > n) break;
            if (dp[tem] == -1) {
                dp[tem] = dp[x] + 1;
                q.push(tem);
            }
        }
    }
    if (*min_element(a.begin(), a.end()) == 1)
        cout << 1 << ' ';
    else
        cout << -1 << ' ';
    for (int i = 2; i <= n; i++) {
        cout << dp[i] << ' ';
    }
    cout << endl;
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