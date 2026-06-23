#include <bits/stdc++.h>
#define endl '\n'
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
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n;
    cin >> n;
    vector<string> ma(3);
    rep(i, 0, 2) cin >> ma[i];
    int tot0 = 0, tot1 = 0, tot2 = 0;
    rep(i, 0, 2 * n - 1) tot0 += (ma[0][i] == '0');
    rep(i, 0, 2 * n - 1) tot1 += (ma[1][i] == '0');
    rep(i, 0, 2 * n - 1) tot2 += (ma[2][i] == '0');
    if (tot0 < n && tot1 < n) {
        string res = "";
        int i = 0, j = 0;
        while (i <= 2 * n - 1 || j <= 2 * n - 1) {
            while (i <= 2 * n - 1 && ma[0][i] != '1') {
                res.push_back(ma[0][i]);
                i++;
            }
            while (j <= 2 * n - 1 && ma[1][j] != '1') {
                res.push_back(ma[1][j]);
                j++;
            }
            if (i <= 2 * n - 1 && j <= 2 * n - 1) {
                res.push_back('1');
                i++, j++;
            } else {
                while (i <= 2 * n - 1) {
                    res.push_back(ma[0][i]);
                    i++;
                }
                while (j <= 2 * n - 1) {
                    res.push_back(ma[1][j]);
                    j++;
                }
            }
        }
        cout << res << endl;
    } else if (tot0 < n && tot2 < n) {
        string res = "";
        int i = 0, j = 0;
        while (i <= 2 * n - 1 || j <= 2 * n - 1) {
            while (i <= 2 * n - 1 && ma[0][i] != '1') {
                res.push_back(ma[0][i]);
                i++;
            }
            while (j <= 2 * n - 1 && ma[2][j] != '1') {
                res.push_back(ma[2][j]);
                j++;
            }
            if (i <= 2 * n - 1 && j <= 2 * n - 1) {
                res.push_back('1');
                i++, j++;
            } else {
                while (i <= 2 * n - 1) {
                    res.push_back(ma[0][i]);
                    i++;
                }
                while (j <= 2 * n - 1) {
                    res.push_back(ma[2][j]);
                    j++;
                }
            }
        }
        cout << res << endl;
    } else if (tot1 < n && tot2 < n) {
        string res = "";
        int i = 0, j = 0;
        while (i <= 2 * n - 1 || j <= 2 * n - 1) {
            while (i <= 2 * n - 1 && ma[1][i] != '1') {
                res.push_back(ma[1][i]);
                i++;
            }
            while (j <= 2 * n - 1 && ma[2][j] != '1') {
                res.push_back(ma[2][j]);
                j++;
            }
            if (i <= 2 * n - 1 && j <= 2 * n - 1) {
                res.push_back('1');
                i++, j++;
            } else {
                while (i <= 2 * n - 1) {
                    res.push_back(ma[1][i]);
                    i++;
                }
                while (j <= 2 * n - 1) {
                    res.push_back(ma[2][j]);
                    j++;
                }
            }
        }
        cout << res << endl;
    } else if (tot0 >= n && tot1 >= n) {
        string res = "";
        int i = 0, j = 0;
        while (i <= 2 * n - 1 || j <= 2 * n - 1) {
            while (i <= 2 * n - 1 && ma[0][i] != '0') {
                res.push_back(ma[0][i]);
                i++;
            }
            while (j <= 2 * n - 1 && ma[1][j] != '0') {
                res.push_back(ma[1][j]);
                j++;
            }
            if (i <= 2 * n - 1 && j <= 2 * n - 1) {
                res.push_back('0');
                i++, j++;
            } else {
                while (i <= 2 * n - 1) {
                    res.push_back(ma[0][i]);
                    i++;
                }
                while (j <= 2 * n - 1) {
                    res.push_back(ma[1][j]);
                    j++;
                }
            }
        }
        cout << res << endl;
    } else if (tot0 >= n && tot2 >= n) {
        string res = "";
        int i = 0, j = 0;
        while (i <= 2 * n - 1 || j <= 2 * n - 1) {
            while (i <= 2 * n - 1 && ma[0][i] != '0') {
                res.push_back(ma[0][i]);
                i++;
            }
            while (j <= 2 * n - 1 && ma[2][j] != '0') {
                res.push_back(ma[2][j]);
                j++;
            }
            if (i <= 2 * n - 1 && j <= 2 * n - 1) {
                res.push_back('0');
                i++, j++;
            } else {
                while (i <= 2 * n - 1) {
                    res.push_back(ma[0][i]);
                    i++;
                }
                while (j <= 2 * n - 1) {
                    res.push_back(ma[2][j]);
                    j++;
                }
            }
        }
        cout << res << endl;
    } else if (tot1 >= n && tot2 >= n) {
        string res = "";
        int i = 0, j = 0;
        while (i <= 2 * n - 1 || j <= 2 * n - 1) {
            while (i <= 2 * n - 1 && ma[1][i] != '0') {
                res.push_back(ma[1][i]);
                i++;
            }
            while (j <= 2 * n - 1 && ma[2][j] != '0') {
                res.push_back(ma[2][j]);
                j++;
            }
            if (i <= 2 * n - 1 && j <= 2 * n - 1) {
                res.push_back('0');
                i++, j++;
            } else {
                while (i <= 2 * n - 1) {
                    res.push_back(ma[1][i]);
                    i++;
                }
                while (j <= 2 * n - 1) {
                    res.push_back(ma[2][j]);
                    j++;
                }
            }
        }
        cout << res << endl;
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
