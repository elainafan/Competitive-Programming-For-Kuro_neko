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
    int n, m, w, x, y;
    cin >> n >> m;
    vvi ma(n);
    rep(i, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    cin >> w;
    vector<string> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vvi ma2(n * w);
    vi deg(n * w);
    int tem = 0;
    rep(i, 0, w - 1) {
        rep(j, 0, n - 1) {
            if (a[j][i] == 'o') tem++;
        }
    }
    rep(i, 0, n - 1) {
        for (int& p : ma[i]) {
            rep(j, 0, w - 1) {
                if (a[i][j] == 'o' && a[p][(j + 1) % w] == 'o') {
                    ma2[j * n + i].push_back((j + 1) % w * n + p);
                    deg[(j + 1) % w * n + p]++;
                }
            }
        }
    }
    rep(i, 0, w - 1) {
        rep(j, 0, n - 1) {
            if (a[j][i] == 'o' && a[j][(i + 1) % w] == 'o') {
                ma2[i * n + j].push_back((i + 1) % w * n + j);
                deg[(i + 1) % w * n + j]++;
            }
        }
    }
    queue<int> q;
    rep(i, 0, w - 1) {
        rep(j, 0, n - 1) {
            if (a[j][i] == 'o' && deg[i * n + j] == 0) q.push(i * n + j);
        }
    }
    int tem2 = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        tem2++;
        for (int& p : ma2[node]) {
            if (--deg[p] == 0) q.push(p);
        }
    }
    if (tem2 < tem)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
