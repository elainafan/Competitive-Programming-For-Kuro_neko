#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void ask(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
}
void report(ll sum) {
    cout << "! " << sum << '\n';
    cout.flush();
}
void solve() {
    int n, op;
    cin >> n;
    vector<vector<int>> ma(n);
    vector<int> dfn(n);
    vector<int> fdfn(n);
    vector<int> siz(n);
    int cnt = 0;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    auto dfs = [&](this auto&& dfs, int x, int pa) -> int {
        dfn[x] = cnt;
        fdfn[cnt] = x;
        cnt++;
        int tem = 1;
        for (int& p : ma[x]) {
            if (p == pa) continue;
            tem += dfs(p, x);
        }
        siz[x] = tem;
        return tem;
    };
    dfs(0, -1);
    for (int i = 0; i < n - 1; i += 2) {
        ask(fdfn[i] + 1, fdfn[i + 1] + 1);
        cin >> op;
        if (op == 1) {
            ask(fdfn[i] + 1, fdfn[i] + 1);
            cin >> op;
            if (op == 1)
                report(fdfn[i] + 1);
            else
                report(fdfn[i + 1] + 1);
            return;
        }
    }
    report(fdfn[n - 1] + 1);
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