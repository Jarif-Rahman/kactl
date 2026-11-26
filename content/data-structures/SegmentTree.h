/**
 * Author: Yeo Swe Hon
 * Description: 0-indexed segtree, point set, inclusive query [l,r].
 * Customise Node, unit (identity) and merge (associative).
 * Usage: st.set(p,{x}), st.qry(l,r)
 * Time: O(\log N)
 * Memory: O(N)
 */
#pragma once

struct Node{
    ll sum;
};
struct SegTree{
    int n;
    Node unit = {0};
    vector<Node> t;
    SegTree(int n): n(n), t(2*n, unit) {}
    Node merge(Node a, Node b){
        return {a.sum + b.sum};
    }
    void set(int p, Node x){
        for(t[p += n] = x; p > 1; p >>= 1) t[p>>1] = merge(t[p&~1], t[p|1]);
    }
    Node qry(int l, int r){
        Node a = unit, b = unit;
        for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
            if(l&1) a = merge(a, t[l++]);
            if(r&1) b = merge(t[--r], b);
        }
        return merge(a,b);
    }
};