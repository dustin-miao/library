#pragma region minimum_queue

#ifndef MINIMUM_QUEUE_HPP
#define MINIMUM_QUEUE_HPP

template<typename T>
class minimum_queue {
	stack<pair<T, T>> s1, s2;

public:
	T query() { return s1.empty() || s2.empty() ? (s1.empty() ? s2.top().second : s1.top().second) : min(s1.top().second, s2.top().second); }

	void push(T x) { s1.emplace(x, s1.empty() ? x : min(x, s1.top().second)); }

	T top() {
		if (s2.empty()) {
			while (!s1.empty()) {
				int x = s1.top().first; s1.pop();
				s2.emplace(x, s2.empty() ? x : min(x, s2.top().second));
			}
		}
		return s2.top().first;
	}

	void pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				int x = s1.top().first; s1.pop();
				s2.emplace(x, s2.empty() ? x : min(x, s2.top().second));
			}
		}
		s2.pop();
	}

	int size() { return s1.size() + s2.size(); }
};

#endif

#pragma endregion minimum_queue