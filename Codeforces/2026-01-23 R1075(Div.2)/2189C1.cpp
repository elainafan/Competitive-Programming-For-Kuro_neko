#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    a[n - 1] = 1;
    map<int, int> ma;
    for (int i = 2; i <= n - 1; i++) ma[1 ^ i]++;
    int idx = 1;
    for (int i = 2; i <= n; i++) {
        if (!ma.count(i)) {
            idx = i;
            break;
        }
    }
    a[0] = idx;
    for (int i = 1; i < n - 1; i++) {
        a[i] = 1 ^ (i + 1);
    }
    for (int p : a) cout << p << ' ';
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