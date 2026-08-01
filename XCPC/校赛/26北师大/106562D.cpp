#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
using ld = long double;

inline constexpr ld EPS = 1e-12L;
inline const ld PI = acosl(-1.0L);

auto sgn(ld x) -> int { return (x > EPS) - (x < -EPS); }

auto eq(ld x, ld y) -> bool { return sgn(x - y) == 0; }

struct Point {
    ld x = 0, y = 0;

    auto operator+(const Point& p) const -> Point { return {x + p.x, y + p.y}; }

    auto operator-(const Point& p) const -> Point { return {x - p.x, y - p.y}; }

    auto operator*(ld k) const -> Point { return {x * k, y * k}; }

    auto operator/(ld k) const -> Point { return {x / k, y / k}; }

    auto operator<(const Point& p) const -> bool { return x != p.x ? x < p.x : y < p.y; }

    auto operator==(const Point& p) const -> bool { return x == p.x && y == p.y; }
};

auto operator*(ld k, const Point& p) -> Point { return p * k; }

auto dot(const Point& a, const Point& b) -> ld { return a.x * b.x + a.y * b.y; }

auto cross(const Point& a, const Point& b) -> ld { return a.x * b.y - a.y * b.x; }

auto cross(const Point& o, const Point& a, const Point& b) -> ld { return cross(a - o, b - o); }

auto norm2(const Point& p) -> ld { return dot(p, p); }

auto length(const Point& p) -> ld { return sqrtl(max<ld>(0, norm2(p))); }

auto dist(const Point& a, const Point& b) -> ld { return length(a - b); }

auto same(const Point& a, const Point& b) -> bool { return eq(a.x, b.x) && eq(a.y, b.y); }

auto perp(const Point& p) -> Point { return {-p.y, p.x}; }

auto rotate(const Point& p, ld rad) -> Point {
    auto c = cosl(rad), s = sinl(rad);
    return {p.x * c - p.y * s, p.x * s + p.y * c};
}

// 用法说明：
// Point 同时表示点和向量，b-a 表示从 a 指向 b 的向量。
// dot(a,b) 是点积；cross(a,b) 是叉积。
// cross(o,a,b) 的符号判断转向：>0 左转，=0 共线，<0 右转。
// norm2(v) 是长度平方，length(v) 是向量长度，dist(a,b) 是两点距离。
// perp(v) 将向量逆时针转 90°；rotate(v,rad) 按弧度旋转。
// same(a,b) 使用 EPS 判等；operator== 是精确判等，只用于排序去重。

// 过 a、b 两点的直线，p 为起点，v 为方向向量。
struct Line {
    Point p, v;

    Line() = default;
    Line(const Point& a, const Point& b) : p(a), v(b - a) {}

    static auto fromVector(const Point& p, const Point& v) -> Line { return Line(p, p + v); }
};

auto parallel(const Line& a, const Line& b) -> bool { return sgn(cross(a.v, b.v)) == 0; }

auto onLine(const Point& p, const Line& l) -> bool {
    if (norm2(l.v) <= EPS * EPS) return same(p, l.p);
    return sgn(cross(l.v, p - l.p)) == 0;
}

auto onSegment(const Point& p, const Point& a, const Point& b) -> bool { return sgn(cross(a, b, p)) == 0 && sgn(dot(p - a, p - b)) <= 0; }

// 平行或重合时没有唯一交点，返回 nullopt。
auto lineIntersection(const Line& a, const Line& b) -> optional<Point> {
    auto d = cross(a.v, b.v);
    if (sgn(d) == 0) return nullopt;
    return a.p + a.v * (cross(b.p - a.p, b.v) / d);
}

auto projection(const Point& p, const Line& l) -> Point {
    auto d = norm2(l.v);
    if (d <= EPS * EPS) return l.p;
    return l.p + l.v * (dot(p - l.p, l.v) / d);
}

auto reflection(const Point& p, const Line& l) -> Point { return projection(p, l) * 2 - p; }

auto distanceToLine(const Point& p, const Line& l) -> ld {
    auto d = length(l.v);
    if (sgn(d) == 0) return dist(p, l.p);
    return fabsl(cross(l.v, p - l.p)) / d;
}

auto distanceToSegment(const Point& p, const Point& a, const Point& b) -> ld {
    auto v = b - a;
    auto d = norm2(v);
    if (d <= EPS * EPS) return dist(p, a);
    auto t = dot(p - a, v) / d;
    if (t <= 0) return dist(p, a);
    if (t >= 1) return dist(p, b);
    return dist(p, a + v * t);
}

// 返回 0/1/2 个点；两线段重叠时返回公共部分的两个端点。
auto segmentIntersection(const Point& a, const Point& b, const Point& c, const Point& d) -> vector<Point> {
    auto c1 = sgn(cross(a, b, c));
    auto c2 = sgn(cross(a, b, d));
    auto c3 = sgn(cross(c, d, a));
    auto c4 = sgn(cross(c, d, b));

    if (c1 * c2 < 0 && c3 * c4 < 0) {
        return {*lineIntersection(Line(a, b), Line(c, d))};
    }

    vector<Point> res;
    auto add = [&](const Point& p) -> void {
        for (const auto& q : res) {
            if (same(p, q)) return;
        }
        res.push_back(p);
    };
    if (onSegment(a, c, d)) add(a);
    if (onSegment(b, c, d)) add(b);
    if (onSegment(c, a, b)) add(c);
    if (onSegment(d, a, b)) add(d);

    sort(res.begin(), res.end());
    if (res.size() > 2) return {res.front(), res.back()};
    return res;
}

auto segmentsIntersect(const Point& a, const Point& b, const Point& c, const Point& d) -> bool {
    return !segmentIntersection(a, b, c, d).empty();
}

auto signedArea2(const vector<Point>& p) -> ld {
    ld res = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        res += cross(p[i], p[(i + 1) % n]);
    }
    return res;
}

auto area(const vector<Point>& p) -> ld { return fabsl(signedArea2(p)) / 2; }

auto perimeter(const vector<Point>& p) -> ld {
    ld res = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        res += dist(p[i], p[(i + 1) % n]);
    }
    return res;
}

// 0：外部，1：边界，2：内部。
auto pointInPolygon(const vector<Point>& poly, const Point& p) -> int {
    bool in = false;
    for (int i = 0, n = poly.size(); i < n; i++) {
        const auto& a = poly[i];
        const auto& b = poly[(i + 1) % n];
        if (onSegment(p, a, b)) return 1;

        if ((a.y > p.y) != (b.y > p.y)) {
            auto x = a.x + (b.x - a.x) * (p.y - a.y) / (b.y - a.y);
            if (sgn(x - p.x) > 0) in = !in;
        }
    }
    return in ? 2 : 0;
}

// 面积为 0 时退化成所有顶点的平均值。
auto centroid(const vector<Point>& p) -> Point {
    if (p.empty()) return {};

    ld sum = 0;
    Point res;
    for (int i = 0, n = p.size(); i < n; i++) {
        auto c = cross(p[i], p[(i + 1) % n]);
        sum += c;
        res = res + (p[i] + p[(i + 1) % n]) * c;
    }
    if (sgn(sum) != 0) return res / (3 * sum);

    res = {};
    for (const auto& x : p) res = res + x;
    return res / p.size();
}

// 返回逆时针凸包，不重复首点；边上的共线点只保留端点。
auto convexHull(vector<Point> p) -> vector<Point> {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) return p;

    vector<Point> h(2 * p.size());
    int k = 0;
    for (const auto& x : p) {
        while (k >= 2 && sgn(cross(h[k - 2], h[k - 1], x)) <= 0) k--;
        h[k++] = x;
    }
    for (int i = int(p.size()) - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && sgn(cross(h[k - 2], h[k - 1], p[i])) <= 0) k--;
        h[k++] = p[i];
    }
    h.resize(k - 1);
    return h;
}

// 返回 0 外部、1 边界、2 内部；h 需要是 convexHull 返回的逆时针严格凸包。
auto pointInConvex(const vector<Point>& h, const Point& p) -> int {
    int n = h.size();
    if (!n) return 0;
    if (n == 1) return same(h[0], p) ? 1 : 0;
    if (n == 2) return onSegment(p, h[0], h[1]) ? 1 : 0;

    int lside = sgn(cross(h[0], h[1], p));
    int rside = sgn(cross(h[0], h[n - 1], p));
    if (lside < 0 || rside > 0) return 0;
    if (lside == 0) return onSegment(p, h[0], h[1]) ? 1 : 0;
    if (rside == 0) return onSegment(p, h[0], h[n - 1]) ? 1 : 0;

    int l = 1, r = n - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (sgn(cross(h[0], h[m], p)) >= 0)
            l = m;
        else
            r = m;
    }
    int side = sgn(cross(h[l], h[l + 1], p));
    if (side < 0) return 0;
    if (side == 0) return onSegment(p, h[l], h[l + 1]) ? 1 : 0;
    return 2;
}

// p 需要是沿边界排列的凸多边形，返回直径。
auto convexDiameter(const vector<Point>& p) -> ld {
    int n = p.size();
    if (n <= 1) return 0;
    if (n == 2) return dist(p[0], p[1]);

    int j = 1;
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        while (fabsl(cross(p[ni] - p[i], p[(j + 1) % n] - p[i])) > fabsl(cross(p[ni] - p[i], p[j] - p[i])) + EPS) {
            j = (j + 1) % n;
        }
        ans = max({ans, norm2(p[i] - p[j]), norm2(p[ni] - p[j])});
    }
    return sqrtl(ans);
}

// 用法说明：
// 多边形用 vector<Point> 表示，顶点顺时针或逆时针依次存放，不重复首点。
// signedArea2(p) 返回两倍有向面积：逆时针为正，顺时针为负。
// area(p) / perimeter(p) 返回面积绝对值 / 周长；centroid(p) 返回重心。
// pointInPolygon(p,q) 判断点与任意简单多边形的位置：
// 返回 0 表示外部，1 表示边界，2 表示内部，复杂度 O(n)。
// convexHull(p) 接收无序点集，返回逆时针严格凸包，不重复首点；
// 重复点会被删除，边上的共线点只保留两端。
// pointInConvex(h,q) 判断点与凸包的位置，返回值同 pointInPolygon；
// h 必须是 convexHull 的返回值，单次查询复杂度 O(log n)。
// convexDiameter(h) 要求 h 已按凸包顺序排列，通常写：
// auto h = convexHull(p);
// ld diameter = convexDiameter(h);
void solve() {
    ll n, q, x, y;
    cin >> n >> q;
    vector<Point> ma;
    set<pll> s;
    rep(i, 0, n - 1) {
        cin >> x >> y;
        ma.emplace_back(x, y);
        s.insert({x, y});
    }
    vector<Point> tem = convexHull(ma);
    rep(i, 0, q - 1) {
        cin >> x >> y;
        if (s.count({x, y})) {
            cout << "YES" << endl;
            continue;
        }
        Point tem2 = {(ld)x, (ld)y};
        if (pointInConvex(tem, tem2) == 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
