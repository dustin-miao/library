#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

#include "geometry/line.hpp"

#include "data-structure/general-segment-tree.hpp"

const int MAX = 5e5 + 5;
const long long MOD = 998244353;

auto merge = [](const line<long long> &l1, const line<long long> &l2) {
    return line<long long>(l1.m * l2.m % MOD, (l1.b * l2.m + l2.b) % MOD);
};

auto apply = [](line<long long> &l1, const line<long long> &l2) { l1 = l2; }

int N, Q;
line<long long> A[MAX];
segtree<line<long long>, decltype(merge), decltype(apply), line<long long>(1, 0)> sgt(merge, apply);

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        long long m, b; 
        cin >> m >> b;
        A[i] = line<long long>(m, b);
    }

    sgt = segtree<line<long long>>(A, A + N);
    sgt.dval = line<long long>(1, 0);

    while (Q--) {
        int t; 
        cin >> t;
        if (t == 0) {
            int i;
            long long m, b;
            cin >> i >> m >> b;
            sgt.update(i, line<long long>(m, b));
        } else if (t == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            cout << sgt.query(l, r - 1)(x) % MOD << '\n';
        }
    }
}