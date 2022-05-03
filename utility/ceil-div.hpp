#pragma region ceil_div

#ifndef CEIL_DIV_HPP
#define CEIL_DIV_HPP

template<typename T>
T ceil_div(T a, T b) { 
	return a / b + ((a ^ b) > 0 && a % b); 
} 

#endif

#pragma endregion ceil_div