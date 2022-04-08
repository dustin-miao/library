template<typename T, typename U>
T fast_pow(T a, U b) { 
	T ret = 1; 
	for (; b; b /= 2) { 
		if (b & 1) 
			ret = ret * a; 
		a = a * a; 
	} 
	return ret; 
}