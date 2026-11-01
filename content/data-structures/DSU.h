/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-24
 * License: CC0
 * Description: Disjoint Set Union with path compression and union by size.
 *              Supports connectivity, component size, and set count.
 *              Supports both 0-based and 1-based indexing.
 * Time: O(alpha(N)) amortized per operation.
 */
#pragma once

struct DSU {
    vector<int> p, sz;
    int cnt;

    DSU(int n) : p(n + 1), sz(n + 1, 1), cnt(n){
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return sz[find(x)]; }
    int numset() { return cnt; }
    bool parent(int x) { return find(x) == x; }

    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b]; cnt--;
        return true;
    }
};