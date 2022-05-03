#pragma region chmax

#ifndef CHMAX_HPP
#define CHMAX_HPP

template<typename T>
bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

#endif

#pragma endregion chmax