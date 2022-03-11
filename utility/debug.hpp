#pragma region debug
#ifndef NDEBUG
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	return os << '(' << p.FF << ", " << p.SS << ')';
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
ostream &operator<<(ostream &os, const map<T1, T2> &s) {
	os << '[';
	if (s.size()) {
		os << '(' << s.begin()->FF << " : " << s.begin()->SS << ')';
		for (auto i = ++s.begin(); i != s.end(); i++)
			os << ", " << '(' << i->FF << " : " << i->SS << ')';
	}
	return os << ']';
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& s) {
	os << '[';
	if (s.size()) {
		os << '(' << s.begin()->FF << " : " << s.begin()->SS << ')';
		for (auto i = ++s.begin(); i != s.end(); i++)
			os << ", " << '(' << i->FF << " : " << i->SS << ')';
	}
	return os << ']';
}

#define dbg1(a) cerr << #a << " = " << a << '\n';
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
