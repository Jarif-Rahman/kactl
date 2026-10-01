/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-02
 * License: CC0
 * Source:
 * Description: Horner's method for polynomial evaluation.
 *              Use horner(a, x) evaluates
 *              A(x)=a[0]x^(n-1)+a[1]x^(n-2)+...+a[n-1].
 *              Rewrites the polynomial as (...((a[0]x+a[1])x+a[2])x...),
 *              avoiding repeated exponentiation and evaluating in linear time.
 *              Coefficients are stored highest degree -> constant term.
 * Time: O(N)
 * Status: tested
 */

template<class T>
T horner(const vector<T> &a, T x){
    T res = 0;
    for(auto &v:a) res = res*x + v;
    return res;
}
