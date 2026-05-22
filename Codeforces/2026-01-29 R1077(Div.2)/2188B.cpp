#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int las = -1;
    int tem = 0;
    int ans = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (s[i] == '1') {
            if (i == 0) {
                las = i;
                ans++;
                continue;
            }
            if (s[i - 1] == '0') {
                if (las == -1) {
                    if (tem == 1)
                        ans += 0;
                    else if (tem <= 3)
                        ans++;
                    else if ((tem - 1) % 3 == 0)
                        ans += (tem - 1) / 3;
                    else
                        ans += (tem - 1) / 3 + 1;
                } else {
                    if (tem <= 2)
                        ans += 0;
                    else if (tem <= 4)
                        ans++;
                    else if ((tem - 2) % 3 == 0)
                        ans += (tem - 2) / 3;
                    else
                        ans += (tem - 2) / 3 + 1;
                }
            }
            las = i;
            tem = 0;
            ans++;
        } else
            tem++;
    }
    if (las == -1) {
        if (tem <= 2)
            ans++;
        else if (tem % 3 == 0)
            ans += tem / 3;
        else
            ans += tem / 3 + 1;
    } else {
        if (tem <= 1)
            ans += 0;
        else if (tem <= 3)
            ans++;
        else if ((tem - 1) % 3 == 0)
            ans += (tem - 1) / 3;
        else
            ans += (tem - 1) / 3 + 1;
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