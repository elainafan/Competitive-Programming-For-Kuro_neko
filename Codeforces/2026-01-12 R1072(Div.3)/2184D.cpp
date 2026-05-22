#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
ll cn[32][32];
void init() {
    for (int i = 0; i <= 31; i++) {
        cn[i][0] = cn[i][i] = 1;
        for (int j = 1; j < i; j++) {
            cn[i][j] = cn[i - 1][j - 1] + cn[i - 1][j];
        }
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    int tem = __lg(n);
    tem++;
    ll ans = 0;
    for (int i = 1; i <= tem - 1; i++) {
        if (2 * i - 1 <= k) continue;
        for (int j = 0; j <= i - 1; j++) {
            if (2 * i - j - 1 > k) ans += cn[i - 1][j];
        }
    }
    if (tem > k) ans++;
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}