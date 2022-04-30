#pragma region chmax

template<typename T>
bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

#pragma endregion chmax