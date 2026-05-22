#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    for (int i = 0; i <= m - 1; i++) cin >> b[i];
    ranges::sort(b);
    string s;
    cin >> s;
    vector<int> mo(k + 1);
    vector<int> l(n, INT_MIN);
    vector<int> r(n, INT_MAX);
    vector<int> die(k + 1, 0);
    map<int, int> ma;
    for (int i = 1; i <= k; i++) {
        if (s[i - 1] == 'L')
            mo[i] = mo[i - 1] - 1;
        else
            mo[i] = mo[i - 1] + 1;
        if (!ma.count(mo[i])) ma[mo[i]] = i;
    }
    for (int i = 0; i <= n - 1; i++) {
        auto x = ranges::lower_bound(b, a[i]);
        if (x == b.end()) {
            l[i] = *(--x) - a[i];
            if (ma.count(l[i])) die[ma[l[i]]]++;
        } else if (x == b.begin()) {
            r[i] = *x - a[i];
            if (ma.count(r[i])) die[ma[r[i]]]++;
        } else {
            r[i] = *x - a[i];
            l[i] = *(--x) - a[i];
            int tem = INT_MAX;
            if (ma.count(l[i])) tem = min(tem, ma[l[i]]);
            if (ma.count(r[i])) tem = min(tem, ma[r[i]]);
            if (tem != INT_MAX) die[tem]++;
        }
    }
    for (int i = 2; i <= k; i++) die[i] += die[i - 1];
    for (int i = 1; i <= k; i++) {
        cout << n - die[i] << ' ';
    }
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