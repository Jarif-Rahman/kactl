/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-02
 * License: CC0
 * Source:
 * Description: Linear sieve computing the smallest prime factor of every integer
 *              up to n. USE: spf(n); minp[x] is the smallest prime factor of x,
 *              and prime contains all primes up to n.
 * Time: O(N)
 * Status: tested
 */

vi minp(MAX_N+1), prime;
void spf(int n){
    for(int i=2;i<=n;i++){
        if (!minp[i]){
            minp[i]=i;
            prime.eb(i);
        }
        for (auto &p:prime){
            if (i*p>n) break;
            minp[i*p]=p;
            if (minp[i]==p) break;
        }
    }
}
