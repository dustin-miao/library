#pragma region chmin

template<typename T>
bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

#pragma endregion chmin