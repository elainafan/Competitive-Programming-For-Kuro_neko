#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    vector<int> b(m);
    vector<int> c(m);
    vector<int> diff(n);
    vector<int> re;
    for (int i = 0; i <= m - 1; i++) {
        cin >> b[i] >> c[i];
        diff[b[i] - 1] += c[i];
        re.push_back(i);
        if (diff[b[i] - 1] + a[b[i] - 1] > h) {
            for (int p : re) {
                diff[b[p] - 1] = 0;
            }
            re.clear();
        }
    }
    for (int i = 0; i <= n - 1; i++) cout << a[i] + diff[i] << ' ';
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