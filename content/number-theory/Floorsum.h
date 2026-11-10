/**
 * Author: Yeo Swe Hon
 * Date: 2026-11-10
 * Description: Computes $\sum_{i=0}^{n-1} \lfloor (ai+b)/m \rfloor$.
 *  Requires n >= 0, m > 0, a >= 0, b >= 0.
 * Time: O(log m)
 */

ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    if (a >= m) ans += (n - 1) * n * (a / m) / 2, a %= m;
    if (b >= m) ans += n * (b / m), b %= m;
    ll y_max = (a * n + b) / m, x_max = y_max * m - b;
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}