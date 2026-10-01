/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-02
 * License: CC0
 * Source:
 * Description: XOR linear basis over GF(2), indexed by highest set bit.
 *              USE: XorBasis xb; xb.add(x); xb.max\_xor(x); xb.min\_xor(x); xb.can\_make(x).
 *              add(x) inserts x if independent and returns whether rank increased.
 *              can\_make(x) checks whether x is representable as xor of inserted values.
 *              max\_xor(x) / min\_xor(x) return the maximum / minimum value obtainable
 *              from x by xoring any subset of inserted values. rank() returns basis dimension.
 * Time: O(LOG)
 * Status: tested
 */

struct XorBasis{
    int LOG;
    vl b;

    XorBasis(int LOG=62) : LOG(LOG), b(LOG,0) {}

    bool add(ll x){
        for(int i=LOG-1;i>=0;i--){
            if (!(x>>i&1)) continue;
            if (!b[i]) return b[i]=x, true;
            x^=b[i];
        }
        return false;
    }

    bool can_make(ll x) {
        for(int i=LOG-1;i>=0;i--){
            if (!(x>>i&1)) continue;
            if (!b[i]) return false;
            x^=b[i];
        }
        return true;
    }

    ll max_xor(ll x=0){
        for(int i=LOG-1;i>=0;i--) x=max(x,x^b[i]);
        return x;
    }

    ll min_xor(ll x=0){
        for(int i=LOG-1;i>=0;i--) x=min(x,x^b[i]);
        return x;
    }

    int rank(){
        int res=0;
        FOR(i,LOG) res+=b[i]!=0;
        return res;
    }
};
