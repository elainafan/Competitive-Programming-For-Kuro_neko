#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
#define endl '\n'
using namespace std;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl tem1;
    vl tem2;
    rep(i, 0, n - 1) {
        if (a[i] % 2 == 1)
            tem1.push_back(a[i]);
        else
            tem2.push_back(a[i]);
    }
    if (tem1.empty() || tem2.empty()) {
        bool flag = true;
        rep(i, 0, n - 2) {
            if (a[i] > a[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    int maxx1 = *max_element(all(tem1));
    int mixx1 = *min_element(all(tem1));
    int maxx2 = *max_element(all(tem2));
    int mixx2 = *min_element(all(tem2));
    multiset<int> s1;
    multiset<int> s2;
    rep(i, 0, n - 1) {
        if (a[i] % 2 == 1) s2.insert(a[i]);
    }
    rep(i, 0, n - 1) {
        if (a[i] % 2 == 0 || s2.empty()) continue;
        if (!s1.empty()) {
            int tem = *prev(s1.end());
            int tem2 = *s2.begin();
            if (tem > maxx2 && tem2 < mixx2) {
                cout << "NO" << endl;
                return;
            }
        }
        s1.insert(a[i]);
        s2.erase(s2.find(a[i]));
    }
    s1.clear();
    s2.clear();
    rep(i, 0, n - 1) {
        if (a[i] % 2 == 0) s2.insert(a[i]);
    }
    rep(i, 0, n - 1) {
        if (a[i] % 2 == 1 || s2.empty()) continue;
        if (!s1.empty()) {
            int tem = *prev(s1.end());
            int tem2 = *s2.begin();
            if (tem > maxx1 && tem2 < mixx1) {
                cout << "NO" << endl;
                return;
            }
        }
        s1.insert(a[i]);
        s2.erase(s2.find(a[i]));
    }
    cout << "YES" << endl;
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
