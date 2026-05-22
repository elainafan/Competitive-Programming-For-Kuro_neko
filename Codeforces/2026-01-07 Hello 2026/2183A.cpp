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
    int cnt0 = 0;
    int cnt1 = 0;
    int tem = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (a[i] == 1) tem++;
        if (a[i] == 0) {
            if (tem > 0) cnt1++;
            tem = 0;
        }
        if (i == n - 1 && tem > 0) cnt1++;
    }
    tem = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (a[i] == 0) tem++;
        if (a[i] == 1) {
            if (tem > 0) cnt0++;
            tem = 0;
        }
        if (i == n - 1 && tem > 0) cnt0++;
    }
    if (cnt1 >= cnt0)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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