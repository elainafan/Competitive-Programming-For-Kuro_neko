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
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define endl '\n'
using namespace std;
void solve() {
    int h, w;
    cin >> h >> w;
    if (h == 1 && w == 1) {
        cout << 0 << endl;
        return;
    }
    if (h == 1) {
        rep(i, 0, w - 1) {
            if (i == 0 || i == w - 1)
                cout << 1 << ' ';
            else
                cout << 2 << ' ';
        }
        cout << endl;
        return;
    }
    if (w == 1) {
        rep(i, 0, h - 1) {
            if (i == 0 || i == h - 1)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        return ;
    }
    rep(i, 0, h - 1) {
        rep(j, 0, w - 1) {
            int tem = 4;
            if (i == 0 || i == h - 1) tem--;
            if (j == 0 || j == w - 1) tem--;
            cout << tem << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}