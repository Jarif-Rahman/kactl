/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-02
 * License: CC0
 * Source:
 * Description: Trie for lowercase strings. Use Trie tr; tr.insert(s);
 *              find(s) checks exact membership; search(s) sums cnt over prefix
 *              nodes of s; lcp(s) returns longest prefix present in the trie.
 *              cnt stores how many inserted strings pass through a node.
 * Time: O(|S|) per operation
 * Status: tested
 */

const int K=26; // 'a' to 'z', change

struct Trie{
    struct Node{
        vi nxt;
        int cnt=0;
        bool is_end=0;
        Node(): nxt(K,-1) {}
    };

    vector<Node> t{{}};

    void insert(const string &s){
        int u=0;
        for(char c:s){
            int x=c-'a';
            if(t[u].nxt[x]==-1)
                t[u].nxt[x]=t.size(), t.eb();
            u=t[u].nxt[x];
            t[u].cnt++;
        }
        t[u].is_end=1;
    }

    bool find(const string &s) const{
        int u=0;
        for(char c:s){
            int x=c-'a';
            if(t[u].nxt[x]==-1) return 0;
            u=t[u].nxt[x];
        }
        return t[u].is_end;
    }

    ll search(const string &s) const{
        int u=0;
        ll ans=0;
        for(char c:s){
            int x=c-'a';
            if(t[u].nxt[x]==-1) break;
            u=t[u].nxt[x];
            ans+=t[u].cnt;
        }
        return ans;
    }

    int lcp(const string &s) const{
        int u=0,len=0;
        for(char c:s){
            int x=c-'a';
            if(t[u].nxt[x]==-1) break;
            u=t[u].nxt[x];
            len++;
        }
        return len;
    }
};
