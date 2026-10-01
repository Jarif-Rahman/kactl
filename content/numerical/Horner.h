/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-02
 * License: CC0
 * Source:
 * Description: Horner's method for polynomial evaluation.
 *              Use horner(a, x) to evaluate
 *              $A(x)=a_0x^{n-1}+a_1x^{n-2}+\cdots+a_{n-1}$.
 *              Rewrites it as $((a_0x+a_1)x+a_2)x+\cdots$,
 *              avoiding repeated exponentiation and evaluating in linear time.
 *              Coefficients are stored highest degree to constant term.
 * Time: O(N)
 * Status: tested
 */

template<class T>
T horner(const vector<T> &a, T x){
    T res = 0;
    for(auto &v:a) res = res*x + v;
    return res;
}
