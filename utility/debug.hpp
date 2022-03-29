#pragma region debug
	#ifndef NDEBUG
		template<typename T1, typename T2>
		ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
			return os << '(' << p.first << ", " << p.second << ')';
		}

		template<typename T1, typename T2, typename T3>
		ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &p) {
			return os << '(' << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ')';
		}

		template<typename T1, typename T2, typename T3, typename T4>
		ostream &operator<<(ostream &os, const tuple<T1, T2, T3, T4> &p) {
			return os << '(' << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ", " << get<3>(p) << ')';
		}

		template<typename T>
		ostream &operator<<(ostream &os, const vector<T> &v) {
			os << '[';
			if (v.size()) {
				os << *v.begin();
				for (auto i = ++v.begin(); i != v.end(); i++)
					os << ", " << (*i);
			}
			return os << ']';
		}

		template<typename T>
		ostream &operator<<(ostream &os, const deque<T> &d) {
			os << '[';
			if (d.size()) {
				os << *d.begin();
				for (auto i = ++d.begin(); i != d.end(); i++)
					os << ", " << (*i);
			}
			return os << ']';
		}

		template<typename T>
		ostream &operator<<(ostream &os, stack<T> s) {
			os << '[';
			if (s.size()) {
				int n = s.size();
				vector<T> v(n);
				for (int i = 0; i < n; i++) {
					v[i] = s.top();
					s.pop();
				}
				os << v[n - 1];
				for (int i = n - 2; i >= 0; i--) { 
					os << ", " << v[i];
					
				}
			}
			return os << "]>";
		}

		template<typename T>
		ostream &operator<<(ostream &os, queue<T> q) {
			os << '[';
			if (q.size()) {
				int n = q.size();
				vector<T> v(n);
				for (int i = 0; i < n; i++) {
					v[i] = q.front();
					q.pop();
				}
				os << v[n - 1];
				for (int i = n - 2; i >= 0; i--) { 
					os << ", " << v[i];
				}
			}
			return os << "]>";
		}

		template<typename T, size_t N>
		ostream &operator<<(ostream &os, const array<T, N> &a) {
			os << '[';
			if (N) {
				os << *a.begin();
				for (auto i = ++a.begin(); i != a.end(); i++)
					os << ", " << (*i);
			}
			return os << ']';
		}

		template<typename T>
		ostream &operator<<(ostream &os, const set<T> &s) {
			os << '[';
			if (s.size()) {
				os << *s.begin();
				for (auto i = ++s.begin(); i != s.end(); i++)
					os << ", " << (*i);
			}
			return os << ']';
		}

		template<typename T>
		ostream &operator<<(ostream &os, const unordered_set<T> &s) {
			os << '[';
			if (s.size()) {
				os << *s.begin();
				for (auto i = ++s.begin(); i != s.end(); i++)
					os << ", " << (*i);
			}
			return os << ']';
		}

		template<typename T>
		ostream &operator<<(ostream &os, const multiset<T> &s) {
			os << '[';
			if (s.size()) {
				os << *s.begin();
				for (auto i = ++s.begin(); i != s.end(); i++)
					os << ", " << (*i);
			}
			return os << ']';
		}

		template<typename T1, typename T2>
		ostream &operator<<(ostream &os, const map<T1, T2> &m) {
			os << '[';
			if (m.size()) {
				os << '(' << m.begin()->first << " : " << m.begin()->second << ')';
				for (auto i = ++m.begin(); i != m.end(); i++)
					os << ", " << '(' << i->first << " : " << i->second << ')';
			}
			return os << ']';
		}

		template<typename T1, typename T2>
		ostream& operator<<(ostream& os, const unordered_map<T1, T2> &m) {
			os << '[';
			if (m.size()) {
				os << '(' << m.begin()->first << " : " << m.begin()->second << ')';
				for (auto i = ++m.begin(); i != m.end(); i++)
					os << ", " << '(' << i->first << " : " << i->second << ')';
			}
			return os << ']';
		}

		#define dbg1(a) 											\
			if ((#a)[0] == '\"') {									\
				if ((#a) == "\"_h1\"")								\
					cerr << "--------------------------------\n";	\
				else if ((#a) == "\"_h2\"")							\
					cerr << "================================\n";	\
				else if ((#a) == "\"_h3\"")							\
					cerr << "≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n";	\
				else if ((#a) == "\"_h4\"")							\
					cerr << "################################\n";	\
				else 												\
					cerr << a;										\
			} else {												\
				cerr << #a << " = " << a << '\n';					\
			}
		#define dbg2(a, b) dbg1(a) dbg1(b)
		#define dbg3(a, b, c) dbg1(a) dbg2(b, c)
		#define dbg4(a, b, c, d) dbg1(a) dbg3(b, c, d)
		#define dbg5(a, b, c, d, e) dbg1(a) dbg4(b, c, d, e)
		#define dbg6(a, b, c, d, e, f) dbg1(a) dbg5(b, c, d, e, f)
		#define dbg7(a, b, c, d, e, f, g) dbg1(a) dbg6(b, c, d, e, f, g)
		#define dbg8(a, b, c, d, e, f, g, h) dbg1(a) dbg7(b, c, d, e, f, g, h)
		#define get_dbg(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
		#define dbg(...) get_dbg(__VA_ARGS__, dbg8, dbg7, dbg6, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)
	#else
		#define dbg(...) 
	#endif
#pragma endregion debug