#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i <= m - 1; i++) cin >> a[i];
    vector<vector<int>> res(n, vector<int>(7, 0));
    ranges::sort(a);
    int tem = n / 2;
    for (int i = 0; i <= tem - 1; i++) res[i][1] = a[i];
    for (int i = n - 1; i > tem - 1; i--) res[i][1] = a[m - (n - i)];
    for (int j = 2; j <= 6; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i <= tem - 1; i++) res[i][j] = a[m - i - 1];
            for (int i = n - 1; i > tem - 1; i--) res[i][j] = a[n - 1 - i];
        } else {
            for (int i = 0; i <= tem - 1; i++) res[i][j] = a[i];
            for (int i = n - 1; i > tem - 1; i--) res[i][j] = a[m - (n - i)];
        }
    }
    for (auto p : res) {
        for (int i = 1; i <= 6; i++) cout << p[i] << ' ';
        cout << endl;
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