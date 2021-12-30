/**
 * @brief A container that supports the union of disjoint sets and the finding
 * of the roots of forests with Small-to-Large Merging. For a dynamic version
 * see Persistant Union Find or Link-Cut Tree. Useful for Kruskal's MST algorithm.
 */
struct UnionFind {
    vector<int> par, sze;
    int max_set; // the size of the largest set

    /**
     * @brief Constructs the UnionFind with size zero
     */
    explicit UnionFind() {}

    /**
     * @brief Constructs the UnionFind with a given size
     * @param n A positive integer that specifies the size
     */
    UnionFind(int n) { init(n); }

    /**
     * @brief Initializes the UnionFind with a given size in
     * linear time.
     * @param n A positive integer that specifies the size
     */
    void init(int n) {
        par.resize(n);
        sze.resize(n);

        iota(par.begin(), par.end(), 0);
        fill(sze.begin(), sze.end(), 1);
        max_set = 1;
    }

    /**
     * @brief Determines the root of the tree where a node is located in
     * amortized O(alpha(n)), where alpha is the inverse ackermann function.
     * @param u A non-negative integer that specifies the node
     */
    int find(int u) {
        if (u == par[u])
            return u;
        return par[u] = find(par[u]);
    }

    /**
     * @brief Merges the trees where two nodes are located in
     * amortized O(alpha(n)), where alpha is the inverse ackermann function.
     * Does nothing if the two nodes are already in the same tree.
     * @param u A non-negative integer that specifies the first node
     * @param v A non-negative integer that specifies the second node
     * @return true, if the merge was successfully completed;
     * false, otherwise
     */
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return 0;

        if (sze[u] > sze[v]) {
            par[v] = u;
            max_set = max(max_set, sze[u] += sze[v]);
        }
        else {
            par[u] = v;
            max_set = max(max_set, sze[v] += sze[u]);
        }
        return 1;
    }

    /**
     * @return Returns the size of the tree containing a given node
     */
    int size(int u) {
        return sze[find(u)];
    }
};
