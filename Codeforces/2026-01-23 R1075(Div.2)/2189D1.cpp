#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    if (s[0] == '0' || s[n - 1] == '0') {
        cout << -1 << endl;
        return;
    }
    ll res = 1;
    map<int, int> ma;
    for (int i = 1; i <= n - 1; i++) {
        if (s[i] == '1') {
            res = res * 2;
            res %= MOD;
            c /= __gcd(c, 2);
        } else {
            res = res * i;
            res %= MOD;
            c /= __gcd(c, i);
        }
    }
    cout << (c == 1 ? -1 : res) << endl;
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