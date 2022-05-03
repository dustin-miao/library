#pragma region floor_div

#ifndef FLOOR_DIV_HPP
#define FLOOR_DIV_HPP

template<typename T>
T floor_div(T a, T b) { 
	return a / b - ((a ^ b) < 0 && a % b); 
}

#endif

#pragma endregion floor_div