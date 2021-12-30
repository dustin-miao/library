---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: A container that supports the union of disjoint sets and the finding
    links: []
  bundledCode: "#line 1 \"data-structure/union-find.hpp\"\n/**\n * @brief A container\
    \ that supports the union of disjoint sets and the finding\n * of the roots of\
    \ forests with Small-to-Large Merging. For a dynamic version\n * see Persistant\
    \ Union Find or Link-Cut Tree. Useful for Kruskal's MST algorithm.\n */\nstruct\
    \ UnionFind {\n    vector<int> par, sze;\n    int max_set; // the size of the\
    \ largest set\n\n    /**\n     * @brief Constructs the UnionFind with size zero\n\
    \     */\n    explicit UnionFind() {}\n\n    /**\n     * @brief Constructs the\
    \ UnionFind with a given size\n     * @param n A positive integer that specifies\
    \ the size\n     */\n    UnionFind(int n) { init(n); }\n\n    /**\n     * @brief\
    \ Initializes the UnionFind with a given size in\n     * linear time.\n     *\
    \ @param n A positive integer that specifies the size\n     */\n    void init(int\
    \ n) {\n        par.resize(n);\n        sze.resize(n);\n\n        iota(par.begin(),\
    \ par.end(), 0);\n        fill(sze.begin(), sze.end(), 1);\n        max_set =\
    \ 1;\n    }\n\n    /**\n     * @brief Determines the root of the tree where a\
    \ node is located in\n     * amortized O(alpha(n)), where alpha is the inverse\
    \ ackermann function.\n     * @param u A non-negative integer that specifies the\
    \ node\n     */\n    int find(int u) {\n        if (u == par[u])\n           \
    \ return u;\n        return par[u] = find(par[u]);\n    }\n\n    /**\n     * @brief\
    \ Merges the trees where two nodes are located in\n     * amortized O(alpha(n)),\
    \ where alpha is the inverse ackermann function.\n     * Does nothing if the two\
    \ nodes are already in the same tree.\n     * @param u A non-negative integer\
    \ that specifies the first node\n     * @param v A non-negative integer that specifies\
    \ the second node\n     * @return true, if the merge was successfully completed;\n\
    \     * false, otherwise\n     */\n    bool merge(int u, int v) {\n        u =\
    \ find(u), v = find(v);\n        if (u == v)\n            return 0;\n\n      \
    \  if (sze[u] > sze[v]) {\n            par[v] = u;\n            max_set = max(max_set,\
    \ sze[u] += sze[v]);\n        }\n        else {\n            par[u] = v;\n   \
    \         max_set = max(max_set, sze[v] += sze[u]);\n        }\n        return\
    \ 1;\n    }\n\n    /**\n     * @return Returns the size of the tree containing\
    \ a given node\n     */\n    int size(int u) {\n        return sze[find(u)];\n\
    \    }\n};\n"
  code: "/**\n * @brief A container that supports the union of disjoint sets and the\
    \ finding\n * of the roots of forests with Small-to-Large Merging. For a dynamic\
    \ version\n * see Persistant Union Find or Link-Cut Tree. Useful for Kruskal's\
    \ MST algorithm.\n */\nstruct UnionFind {\n    vector<int> par, sze;\n    int\
    \ max_set; // the size of the largest set\n\n    /**\n     * @brief Constructs\
    \ the UnionFind with size zero\n     */\n    explicit UnionFind() {}\n\n    /**\n\
    \     * @brief Constructs the UnionFind with a given size\n     * @param n A positive\
    \ integer that specifies the size\n     */\n    UnionFind(int n) { init(n); }\n\
    \n    /**\n     * @brief Initializes the UnionFind with a given size in\n    \
    \ * linear time.\n     * @param n A positive integer that specifies the size\n\
    \     */\n    void init(int n) {\n        par.resize(n);\n        sze.resize(n);\n\
    \n        iota(par.begin(), par.end(), 0);\n        fill(sze.begin(), sze.end(),\
    \ 1);\n        max_set = 1;\n    }\n\n    /**\n     * @brief Determines the root\
    \ of the tree where a node is located in\n     * amortized O(alpha(n)), where\
    \ alpha is the inverse ackermann function.\n     * @param u A non-negative integer\
    \ that specifies the node\n     */\n    int find(int u) {\n        if (u == par[u])\n\
    \            return u;\n        return par[u] = find(par[u]);\n    }\n\n    /**\n\
    \     * @brief Merges the trees where two nodes are located in\n     * amortized\
    \ O(alpha(n)), where alpha is the inverse ackermann function.\n     * Does nothing\
    \ if the two nodes are already in the same tree.\n     * @param u A non-negative\
    \ integer that specifies the first node\n     * @param v A non-negative integer\
    \ that specifies the second node\n     * @return true, if the merge was successfully\
    \ completed;\n     * false, otherwise\n     */\n    bool merge(int u, int v) {\n\
    \        u = find(u), v = find(v);\n        if (u == v)\n            return 0;\n\
    \n        if (sze[u] > sze[v]) {\n            par[v] = u;\n            max_set\
    \ = max(max_set, sze[u] += sze[v]);\n        }\n        else {\n            par[u]\
    \ = v;\n            max_set = max(max_set, sze[v] += sze[u]);\n        }\n   \
    \     return 1;\n    }\n\n    /**\n     * @return Returns the size of the tree\
    \ containing a given node\n     */\n    int size(int u) {\n        return sze[find(u)];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.hpp
  requiredBy: []
  timestamp: '2021-12-29 21:33:13-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/union-find.hpp
layout: document
redirect_from:
- /library/data-structure/union-find.hpp
- /library/data-structure/union-find.hpp.html
title: A container that supports the union of disjoint sets and the finding
---
