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
    ranges::sort(a);
    int tem = 1;
    int maxx = 1;
    int las = a[0];
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] == las + 1) {
            tem++;
            las = a[i];
            maxx = max(maxx, tem);
            continue;
        }
        if (a[i] == a[i - 1]) continue;
        las = a[i];
        tem = 1;
    }
    cout << maxx << endl;
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