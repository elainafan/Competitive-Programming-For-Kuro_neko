#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    p[n - 1] = 1;
    int l = n, r = 2;
    for (int i = n - 2; i >= 0; i--) {
        if ((n - i - 1) % 2) {
            p[i] = l;
            l--;
        } else {
            p[i] = r;
            r++;
        }
    }
    for (int& q : p) cout << q << ' ';
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
