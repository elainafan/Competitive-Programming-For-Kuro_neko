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
    vector<int> pre(n + 1);
    vector<int> suf(n + 2);
    sort(a.rbegin(), a.rend());
    map<int, int> ma;
    for (int i = 1; i <= n; i++) {
        ma[a[i - 1]]++;
        int cnt = 0;
        for (auto [x, y] : ma) {
            if (x == cnt)
                cnt++;
            else
                break;
        }
        pre[i] = cnt;
    }
    ma.clear();
    for (int i = n; i >= 1; i--) {
        ma[a[i - 1]]++;
        int cnt = 0;
        for (auto [x, y] : ma) {
            if (x == cnt)
                cnt++;
            else
                break;
        }
        suf[i] = cnt;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (pre[i] == suf[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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