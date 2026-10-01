/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-02
 * License: CC0
 * Source:
 * Description: XOR linear basis over GF(2). Stores independent values by highest
 *              set bit. USE: XorBasis xb; xb.add(x); xb.max_xor(); xb.can_make(x).
 *              add(x) inserts x if independent and returns whether rank increased.
 *              can_make(x) checks if x can be formed by xor of inserted values.
 *              max_xor(x) returns the maximum value obtainable from x by xoring
 *              any subset of inserted values. rank() returns basis dimension.
 * Time: O(LOG) per operation
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
