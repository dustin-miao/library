template<typename T>
struct segtree {
    int n;
    vector<T> tree;

protected:
    T dval = T();

    T merge(const T &a, const T &b) { return a + b; }

    void apply(T &a, const T &b) { a = b; }

private:
    T query(int l, int r, int t, int tl, int tr) {
        if (r < tl || tr < l)
            return dval;
        if (l <= tl && tr <= r)
            return tree[t];
        int tm = (tl + tr) >> 1;
        return merge(query(l, r, t << 1, tl, tm), query(l, r, t << 1 | 1, tm + 1, tr));
    }

    void update(int i, T v, int t, int tl, int tr) {
        if (tl == tr) {
            apply(tree[t], v);
            return;
        }
        int tm = (tl + tr) >> 1;
        if (i <= tm)
            update(i, v, t << 1, tl, tm);
        else 
            update(i, v, t << 1 | 1, tm + 1, tr);
        tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
    }

public:
    segtree() = default;

    segtree(int _n) : n(_n) {
        tree.resize(4 * n);
        for (int i = 0; i < n; i++)
            update(i, dval);
    }

    template<typename Iterator>
    segtree(Iterator begin, Iterator end) : n(distance(begin, end)) {
		tree.resize(4 * n);
        for (int i = 0; i < n; i++, begin++)
            update(i, *begin);
    }

    T query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }

    T operator[](int i) { return query(i, i); }

    void update(int i, T v) {
        update(i, v, 1, 0, n - 1);
    }
};