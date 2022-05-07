#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/sliding-window-aggregate.hpp"
#include "utility/mint.hpp"

int main() {
	MOD = 998244353;

	int Q;
	cin >> Q;

	struct sliding_window_aggregate_template {
		using type = pair<mint, mint>;
		const type default_value = {1, 0};
		type merge(type a, type b) { return type{a.first * b.first, a.second * b.first + b.second}; }
	};

	sliding_window_aggregate<sliding_window_aggregate_template> swa;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 0) {
			mint a, b;
			cin >> a >> b;
			swa.push(make_pair(a, b));
		} else if (t == 1) {
			assert(!swa.empty());
			swa.pop();
		} else if (t == 2) {
			mint x;
			cin >> x;
			auto [a, b] = swa.query();
			cout << a * x + b << '\n';
		}
	}
}