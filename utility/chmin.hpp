#pragma region chmin

#ifndef CHMIN_HPP
#define CHMIN_HPP

template<typename T>
bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

#endif

#pragma endregion chmin