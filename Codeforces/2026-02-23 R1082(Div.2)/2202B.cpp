#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
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
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    if (n % 2 == 1) {
        if (s[0] == 'b') {
            cout << "NO" << endl;
            return;
        }
        for (int i = 2; i <= n - 1; i += 2) {
            if (s[i] == 'a' && s[i - 1] == 'a' || s[i] == 'b' && s[i - 1] == 'b') {
                cout << "NO" << endl;
                return;
            }
        }
    } else {
        for (int i = 1; i <= n - 1; i += 2) {
            if (s[i] == 'a' && s[i - 1] == 'a' || s[i] == 'b' && s[i - 1] == 'b') {
                cout << "NO" << endl;
                return;
            }
        }
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
