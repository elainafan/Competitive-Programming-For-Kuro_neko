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
struct Node {
    int son[2];
    Node() { son[0] = son[1] = -1; }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> ma(n);
    map<string, int> ma2;
    vector<Node> tree(1);
    rep(i, 0, n - 1) {
        cin >> ma[i];
        ma2[ma[i]]++;
        int cur = 0;
        for (char c : ma[i]) {
            int b = c - '0';
            if (tree[cur].son[b] == -1) {
                tree[cur].son[b] = sz(tree);
                tree.emplace_back();
            }
            cur = tree[cur].son[b];
        }
    }
    if (m <= 30 && sz(ma2) == (1 << m)) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    string res;
    bool flag = false;
    auto dfs = [&](this auto&& dfs, int x, int cnt) -> void {
        if (flag) return;
        if (cnt == m) return;
        rep(i, 0, 1) {
            if (flag) return;
            if (tree[x].son[i] == -1) {
                res.push_back(char('0' + i));
                while (sz(res) < m) {
                    res.push_back('0');
                }
                flag = true;
                return;
            }
            res.push_back(char('0' + i));
            dfs(tree[x].son[i], cnt + 1);
            if (flag) return;
            res.pop_back();
        }
    };
    dfs(0, 0);
    rep(i, 0, m - 1) { res[i] = (res[i] == '0') ? '1' : '0'; }
    cout << res << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}