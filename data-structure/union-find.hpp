struct UnionFind {
    vector<int> parent, setsize;

    UnionFind() = default;

    UnionFind(int n) { init(n); }

    void init(int n) {
        parent.resize(n);
        setsize.resize(n);
        iota(parent.begin(), parent.end(), 0);
        fill(setsize.begin(), setsize.end(), 1);
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        if (setsize[u] > setsize[v]) {
            parent[v] = u;
            setsize[u] += setsize[v];
        } else {
            parent[u] = v;
            setsize[v] += setsize[u];
        }
        return true;
    }

    int size(int u) {
        return setsize[find(u)];
    }
};
