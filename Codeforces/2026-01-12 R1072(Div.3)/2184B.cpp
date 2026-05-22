#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int s, k, m;
    cin >> s >> k >> m;
    if (k >= s) {
        int tem = m % k;
        if (tem == 0)
            cout << s << endl;
        else
            cout << max(0, s - tem) << endl;
        return;
    } else {
        int tem = m % k;
        if (tem == 0) {
            int tem2 = m / k;
            if (tem2 % 2 == 0)
                cout << s << endl;
            else
                cout << k << endl;
        } else {
            int tem2 = m / k;
            if (tem2 % 2 == 1)
                cout << max(0, k - tem) << endl;
            else
                cout << max(0, s - tem) << endl;
        }
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