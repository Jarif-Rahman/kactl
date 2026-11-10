/**
 * Author: Yeo Swe Hon
 * Date: 2026-11-10
 * Description: Finds a primitive root $g$ modulo prime $p$.
 *  Every nonzero residue is uniquely $g^k \bmod p$ for $0 \le k < p-1$,
 *  allowing multiplication modulo $p$ to become addition of exponents modulo $p-1$.
 * Time: O(sqrt(p) + p log^2(p))
 */

ll primitive_root(ll p){
    ll n = p-1; vl f;
    for (ll i=2; i * i <= n; i++) if (n%i==0){
        f.push_back(i);
        while (n%i==0) n/=i;
    }
    if (n > 1) f.push_back(n);
    for (ll g = 1; g < p; g++){
        bool ok = true;
        for (ll q : f) if (modpow(g, (p-1)/q, p) == 1) ok = false; // g^(p-1)/q mod p
        if (ok) return g;
    }
    return -1;
}