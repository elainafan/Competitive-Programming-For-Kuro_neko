#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0 && (n - i) % 3 == 0) {
            int tem = i / 2, tem2 = (n - i) / 3;
            if (tem % 2 == 0) {
                if (tem2 % 2 == 1) {
                    if (tem != 0)
                        ans = min(ans, 1);
                    else
                        ans = min(ans, 3);
                } else
                    ans = min(ans, 0);
            } else {
                if (tem2 % 2 == 1)
                    ans = min(ans, 1);
                else {
                    ans = min(ans, 2);
                }
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