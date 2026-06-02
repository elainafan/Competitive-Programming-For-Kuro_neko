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
void solve1() {
    int n, m, x, y;
    cin >> n >> m;
    vvi ma(n);
    rep(i, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vi dis(n, -1);
    queue<int> q;
    rep(st, 0, n - 1) {
        if (dis[st] != -1) continue;
        while (!q.empty()) q.pop();
        dis[st] = 0;
        q.push(st);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int p : ma[node]) {
                if (dis[p] == -1) {
                    dis[p] = dis[node] + 1;
                    q.push(p);
                }
            }
        }
    }
    string res = "";
    rep(i, 0, n - 1) {
        if (dis[i] % 3 == 0)
            res.push_back('r');
        else if (dis[i] % 3 == 1)
            res.push_back('g');
        else
            res.push_back('b');
    }
    cout << res << endl;
    return;
}
void solve2() {
    ll q, n;
    string s;
    cin >> q;
    rep(i, 0, q - 1) {
        cin >> n >> s;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int idx0 = -1, idx1 = -1, idx2 = -1;
        rep(j, 0, n - 1) {
            if (s[j] == 'r') {
                cnt0++;
                idx0 = j + 1;
            } else if (s[j] == 'g') {
                cnt1++;
                idx1 = j + 1;
            } else {
                cnt2++;
                idx2 = j + 1;
            }
        }
        if (cnt0 == 0 && cnt1 == 0)
            cout << idx2 << endl;
        else if (cnt0 == 0 && cnt2 == 0)
            cout << idx1 << endl;
        else if (cnt1 == 0 && cnt2 == 0)
            cout << idx0 << endl;
        else if (cnt0 == 0)
            cout << idx2 << endl;
        else if (cnt1 == 0)
            cout << idx0 << endl;
        else if (cnt2 == 0)
            cout << idx1 << endl;
    }
    return;
}
void solve(string x) {
    int t;
    cin >> t;
    while (t--) {
        if (x == "first")
            solve1();
        else
            solve2();
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string op;
    cin >> op;
    solve(op);
    return 0;
}
