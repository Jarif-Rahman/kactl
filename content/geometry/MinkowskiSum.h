
/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-24
 * License: CC0
 * Description: Computes the Minkowski sum of two point sets.
 *              First constructs their convex hulls, then merges
 *              their edge vectors and computes the resulting hull.
 *              Requires ConvexHull to return CCW vertices
 *              starting from the bottommost-leftmost point.
 * Time: O(N log N + M log M)
 */
auto minkowski(vector<P> a, vector<P> b) {
    a = ConvexHull(a), b = ConvexHull(b);
    int n = a.size(), m = b.size();
    vector<P> c = {a[0] + b[0]}, s1, s2;
    for (int i = 0; i < n; ++i) s1.pb(a[(i + 1) % n] - a[i]);
    for (int i = 0; i < m; i++) s2.pb(b[(i + 1) % m] - b[i]);
    for (int p1 = 0, p2 = 0; p1 < n || p2 < m;)
        if (p2 == m || ( p1 < n && sgn(s1[p1].cross(s2[p2])) >= 0 )) c.push_back(c.back() + s1[p1++]);
        else c.push_back(c.back() + s2[p2++]);
    return ConvexHull(c);
}