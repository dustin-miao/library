#pragma region matrix

template<typename T, size_t N>
struct matrix : array<array<T, N>, N> {
	template<typename U>
	matrix<T, N> operator*=(const matrix<U, N> &m) {
		matrix<T, N> t = (*this); 
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				at(r).at(c) = T();
				for (int i = 0; i < N; i++)
					rat(r).at(c) += t[r][i] * m[i][c];
			}
		}
		return (*this);
	}
};

template<typename T, size_t N>
matrix<T, N> operator*(matrix<T, N> m, const matrix<T, N> &n) { return m *= n; }

#pragma endregion matrix