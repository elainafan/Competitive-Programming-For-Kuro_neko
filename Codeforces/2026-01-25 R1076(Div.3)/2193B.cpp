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
    int cnt = n;
    int idx = -1;
    for (int i = 0; i <= n - 1; i++) {
        if (a[i] == cnt) {
            cnt--;
        } else {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        for (int p : a) cout << p << ' ';
        cout << endl;
        return;
    }
    int idx2 = -1;
    for (int i = 0; i <= n - 1; i++) {
        if (a[i] == cnt) {
            idx2 = i;
            break;
        }
    }
    auto ndp = a;
    for (int i = 0; i <= n - 1; i++) {
        if (i >= idx && i <= idx2)
            ndp[i] = a[idx2 - (i - idx)];
        else
            ndp[i] = a[i];
    }
    for (int p : ndp) cout << p << ' ';
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