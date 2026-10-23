
/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-24
 * License: CC0
 * Description: Computes the Minkowski sum of two convex polygons
 *              in counterclockwise (CCW) order in linear time.
 *              Rotates both polygons to start at the bottommost-
 *              leftmost vertex, then merges edges by angle using
 *              cross products. Requires non-degenerate polygons.
 * Time: O(N + M)
 */
void reorder(vector<P> &V) {
    rotate(V.begin(), min_element(all(V), [&](P a, P b){
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    }), V.end());
}

auto minkowski(vector<P> a, vector<P> b) {
    // P, Q: convex polygon, CCW order
    reorder(a), reorder(b);
    int n = a.size(), m = b.size();
    a.pb(a[0]), a.pb(a[1]), b.pb(b[0]), b.pb(b[1]);
    vector<P> ans;
    for (int i = 0, j = 0; i < n || j < m;){
        ans.pb(a[i] + b[j]);
        if (i == n) j++;
        else if (j == m) i++;
        else{
            auto val = (a[i + 1] - a[i]).cross(b[j + 1] - b[j]);
            if (val >= 0) i++;
            if (val <= 0) j++;
        }
    }
    return ans;
}