#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    int tem = popcount((unsigned)n);
    if (tem == 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> a(n + 1);
    map<int, int> ma;
    a[n] = 1;
    ma[1]++;
    for (int i = 2; i <= n - 1; i++) {
        a[i] = (i ^ 1);
        ma[i ^ 1]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!ma.count(i)) {
            a[1] = i;
            break;
        }
    }
    swap(a[1], a[lowbit(n)]);
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
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