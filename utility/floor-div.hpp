#pragma region floor_div

template<typename T>
T floor_div(T a, T b) { 
	return a / b - ((a ^ b) < 0 && a % b); 
}

#pragma endregion floor_div