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
const ll MOD = 998244353;
void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    int l1 = 0, r1 = n - 1;
    while (l1 <= r1 && s[l1] == s[r1]) {
        l1++, r1--;
    }
    if (l1 > r1) {
        cout << 0 << endl;
        return;
    }
    string tem = s.substr(l1, r1 - l1 + 1);
    int m = sz(tem);
    int l = 2, r = m, ans = 2, mid;
    auto check = [&](int mid) -> bool {
        if (mid > m / 2) {
            vi tem2(26);
            vi tem3(26);
            rep(i, 0, mid - 1) tem2[tem[i] - 'a']++;
            rep(i, mid, m - 1) tem3[tem[i] - 'a']++;
            bool flag = true;
            rep(i, 0, 25) {
                if (tem2[i] >= tem3[i])
                    continue;
                else
                    flag = false;
            }
            if (flag) return true;
            flag = true;
            rep(i, 0, 25) tem2[i] = 0, tem3[i] = 0;
            rep(i, m - mid, m - 1) tem2[tem[i] - 'a']++;
            rep(i, 0, m - mid - 1) tem3[tem[i] - 'a']++;
            rep(i, 0, 25) {
                if (tem2[i] >= tem3[i] && (tem2[i] - tem3[i]) % 2 == 0)
                    continue;
                else
                    flag = false;
            }
            return flag;
        } else {
            rep(i, mid, m / 2 - 1) {
                if (tem[i] != tem[m - 1 - i]) return false;
            }
            vi tem2(26);
            vi tem3(26);
            rep(i, 0, mid - 1) tem2[tem[i] - 'a']++;
            rep(i, m - mid, m - 1) tem3[tem[i] - 'a']++;
            bool flag = true;
            rep(i, 0, 25) {
                if (tem2[i] == tem3[i])
                    continue;
                else
                    flag = false;
            }
            if (flag) return true;
            flag = true;
            rep(i, 0, 25) tem2[i] = 0, tem3[i] = 0;
            rep(i, 0, mid - 1) tem3[tem[i] - 'a']++;
            rep(i, m - mid, m - 1) tem2[tem[i] - 'a']++;
            rep(i, 0, 25) {
                if (tem2[i] == tem3[i])
                    continue;
                else
                    flag = false;
            }
            return flag;
        }
    };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << endl;
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