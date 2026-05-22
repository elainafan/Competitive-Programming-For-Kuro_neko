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
    int cnt0 = 0, cnt1 = 0;
    vector<int> res;
    for (int i = 0; i <= n - 1; i++) {
        if (s[i] == '0') {
            cnt0++;
        } else if (s[i] == '1')
            cnt1++;
    }
    vector<int> res1;
    for (int i = 0; i <= cnt0 - 1; i++) {
        if (s[i] == '1') res1.push_back(i + 1);
    }
    for (int i = cnt0; i <= n - 1; i++) {
        if (s[i] == '0') res.push_back(i + 1);
    }
    if (cnt1 == 0 || cnt0 == 0 || res1.size() == 0) {
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
    cout << 2 * res1.size() << endl;
    for (int p : res1) cout << p << ' ';
    for (int p : res) cout << p << ' ';
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