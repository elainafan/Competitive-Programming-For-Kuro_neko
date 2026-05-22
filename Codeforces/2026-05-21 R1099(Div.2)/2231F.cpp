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
const ll MX = 2e5 + 5;
vi is_square(MX, 0);
vi sum(MX, 0);
vi mixx(MX, INT_MAX);
vi square;
auto init = [] {
    for (int i = 1; i * i <= MX; i++) {
        square.push_back(i * i);
        is_square[i * i] = 1;
    }
    for (auto& p : square) {
        for (auto& q : square) {
            if (p + q >= MX) break;
            sum[p + q] = 1;
        }
    }
    int m = sz(square);
    rep(i, 0, m - 1) {
        rep(j, i + 1, m - 1) {
            if (square[j] - square[i] < MX) mixx[square[j] - square[i]] = min(mixx[square[j] - square[i]], square[i]);
        }
    }
    return 0;
}();
void solve() {
    int n, q, x, y;
    cin >> n >> q;
    auto check = [&](int x, int y) -> bool {
        if (y == x) return true;
        if (y < x) swap(y, x);
        if (y - x == (int)sqrt(y - x) * (int)sqrt(y - x)) return true;
        if (sum[y - x]) return true;
        int tem = max(x - 1, n - y);
        if (mixx[y - x] <= tem) return true;
        return false;
    };
    auto check2 = [&](int x, int y) -> bool {
        if (y < x) swap(x, y);
        for (int& p : square) {
            int tem = x + p;
            if (tem <= n && check(tem, y)) return true;
            tem = x - p;
            if (tem >= 1 && check(tem, y)) return true;
        }
        return false;
    };
    rep(i, 0, q - 1) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (x == y) {
            cout << 0 << endl;
            continue;
        }
        int tem = (int)sqrt(y - x);
        if (tem * tem == y - x) {
            cout << 1 << endl;
            continue;
        }
        if (check(x, y)) {
            cout << 2 << endl;
            continue;
        }
        if (check2(x, y)) {
            cout << 3 << endl;
            continue;
        }
        cout << 4 << endl;
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
