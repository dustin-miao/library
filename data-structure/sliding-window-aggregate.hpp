#pragma region sliding_window_aggregate

#ifndef SLIDING_WINDOX_AGGREGATE_HPP
#define SLIDING_WINDOX_AGGREGATE_HPP

template<class sliding_window_aggregate_template>
class sliding_window_aggregate : public sliding_window_aggregate_template {
	using T = typename sliding_window_aggregate_template::type;
	using sliding_window_aggregate_template::default_value;
	using sliding_window_aggregate_template::merge;

	stack<pair<T, T>> s1, s2;
	T ret1, ret2;

public:
	sliding_window_aggregate() { init(); };

	void init() { 
		while (!s1.empty())
			s1.pop();
		while (!s2.empty())
			s2.pop();
		ret1 = ret2 = default_value; 
	}

	T query() { return merge(ret2, ret1); }

	void push(T x) {
		if (s2.empty()) {
			s2.emplace(x, ret2 = merge(x, ret2));
			while (!s1.empty()) {
				T y = s1.top().first; s1.pop();
				s2.emplace(y, ret2 = merge(y, ret2));
			}
			ret1 = default_value;
		} else {
			s1.emplace(x, ret1 = merge(ret1, x));
		}
	}

	void pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				T x = s1.top().first; s1.pop();
				s2.emplace(x, ret2 = merge(x, ret2));
			}
			ret1 = default_value;
		}
		s2.pop();
		ret2 = s2.empty() ? default_value : s2.top().second;
	}

	int size() { return s1.size() + s2.size(); }	

	bool empty() { return size() == 0; }
};

#endif

#pragma endregion sliding_window_aggregate
