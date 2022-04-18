#pragma region matrix

template<typename T>
class matrix {
	int n;
	vector<vector<T>> mat;

public:
	matrix() = default;

	matrix(int _n) {
		n = _n;
		mat.assign(n, vector<T>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mat[i][j] = int(i == j);
	}

	matrix(int _n, T v) { 
		n = _n;
		mat.assign(n, vector<T>(n, v)); 
	}

	vector<T> &operator[](int i) { return mat[i]; }

	const vector<T> &operator[](int i) const { return mat[i]; }

	const int size() const { return n; }

	void fill(T v = T{}) {
		for (int i = 0; i < n; i++)
			fill(mat[i].begin(), mat[i].end(), v);
	}

	void resize(int _n, T v = T{}) { 
		n = _n;
		mat.resize(n);
		for (int i = 0; i < n; i++)
			mat[i].resize(n, v);
	}

	matrix<T> operator+=(const matrix<T> &m) {
		assert(size() == m.size());
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mat[i][j] += m[i][j];
		return *this;
	}

	matrix<T> operator-=(const matrix<T> &m) {
		assert(size() == m.size());
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mat[i][j] -= m[i][j];
		return *this;
	}

	matrix<T> operator *=(const matrix<T> &m) {
		assert(size() == m.size());
		matrix<T> ret(n, T{});
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
				for (int j = 0; j < n; j++)
					ret[i][j] += mat[i][k] * m[k][j];
		return *this = move(ret);
	}
};

template<typename T>
matrix<T> operator+(matrix<T> m, const matrix<T> &n) { return m += n; }

template<typename T>
matrix<T> operator-(matrix<T> m, const matrix<T> &n) { return m -= n; }

template<typename T>
matrix<T> operator*(matrix<T> m, const matrix<T> &n) { return m *= n; }

template<typename T>
vector<T> operator*(const matrix<T> &m, const vector<T> &n) {
	assert(m.size() == n.size());
	int s = m.size();
	vector<T> ret(s);
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			ret[i] += m[i][j] * n[j];
	return ret;
}

template<typename T>
bool operator==(const matrix<T> &m, const matrix<T> &n) {
	if (m.size() != n.size())
		return false;
	int s = m.size();
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			if (m[i][j] != n[i][j])
				return false;
	return true;
}

template<typename T>
bool operator!=(const matrix<T> &m, const matrix<T> &n) { return !(m == n); }

template<typename T>
ostream &operator<<(ostream &os, const matrix<T> &m) {
	int s = m.size();
	for (int i = 0; i < s; i++) {
		os << '[';
		for (int j = 0; j < s; j++) {
			os << m[i][j];
			if (j != s - 1)
				os << ", ";
		}
		os << "]\n";
	}
	return os;
}

template<typename T, typename U>
matrix<T> fast_pow(matrix<T> a, U b) {
	int n = a.size();
	matrix<T> ret(n);
	for (; b; b /= 2) {
		if (b & 1)
			ret *= a;
		a *= a;
	}
	return ret;
}

#pragma endregion matrix
