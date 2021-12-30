template<typename T>
struct FenwickTree {
    int n;
    vector<T> tree;

    FenwickTree() = default;

    FenwickTree(int _n) : n(_n + 1) {
        tree.assign(n, T());
    }

    template<class Iterator>
    FenwickTree(Iterator begin, Iterator end) : n(distance(begin, end) + 1) {
        tree.resize(n);
        for (int i = 1; begin != end; i++, begin++)
            update(i, *begin);
    }

    T query(int i) {
        T ret = 0;
        for (; i; i -= i & -i)
            ret += tree[i];
        return ret;
    }

    T query(int l, int r) { return query(r) - query(l - 1); }

    T operator[](int i) { return query(i, i); }

    void update(int i, T v) {
        for (; i <= n; i += i & -i)
            tree[i] += v;
    }
};
