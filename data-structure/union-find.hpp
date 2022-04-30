#pragma region union_find

struct union_find {
    vector<int> par, siz;

    union_find() = default;

    union_find(int n) { init(n); }

    void init(int n) {
        par.resize(n);
        siz.resize(n);
        iota(par.begin(), par.end(), 0);
        fill(siz.begin(), siz.end(), 1);
    }

    int find(int u) {
        if (u == par[u])
            return u;
        return par[u] = find(par[u]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        if (siz[u] > siz[v]) {
            par[v] = u;
            siz[u] += siz[v];
        } else {
            par[u] = v;
            siz[v] += siz[u];
        }
        return true;
    }

    int size(int u) { return siz[find(u)]; }
};

#pragma endregion union_find