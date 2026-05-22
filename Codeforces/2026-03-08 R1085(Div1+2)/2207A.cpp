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
    int maxx = 0;
    int mixx = 0;
    int las = -3;
    int cnt = 0;
    int st = -1;
    vi res;
    rep(i, 0, n - 1) {
        if (s[i] == '1') {
            if (st == -1) {
                st = i;
                las = i;
            } else {
                if (i - las <= 2) {
                    las = i;
                } else {
                    maxx += las - st + 1;
                    mixx += (las - st + 1) / 2 + 1;
                    st = i;
                    las = i;
                }
            }
        }
    }
    if (st != -1) {
        maxx += las - st + 1;
        mixx += (las - st + 1) / 2 + 1;
    }
    cout << mixx << ' ' << maxx << endl;
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
