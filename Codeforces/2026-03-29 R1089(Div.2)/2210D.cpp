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
    string s, t;
    cin >> s >> t;
    auto cnt_leaves = [&](const string& s) -> int {
        int cnt = 0;
        rep(i, 0, n - 2) {
            if (s[i] == '(' && s[i + 1] == ')') cnt++;
        }
        return cnt;
    };
    auto cnt_matches = [&](const string& s) -> int {
        int cnt = 0;
        vi match(n);
        stack<int> st;
        rep(i, 0, n - 1) {
            if (s[i]=='(') {
                st.push(i);
                continue;
            }
            match[st.top()]=i;
            st.pop();
        }
        int l = 0, r = n - 1;
        while (match[l] == r) {
            l++;
            r--;
            cnt++;
        }
        return cnt;
    };
    if (cnt_leaves(s) == cnt_leaves(t) && cnt_matches(s) == cnt_matches(t))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
